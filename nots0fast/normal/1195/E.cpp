#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long
#define double long double
#define MAX 3030
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353 ;
 
 template<typename T>
class range_minimum_query{
public:
	std::vector<T> data;
	std::vector<std::vector<int> > block;
	std::vector<int> sblock;
	std::vector<int> lookup;
	int N;
	int lg;
	int min(int a,int b){
		return data[b]<data[a]?b:a;
	}
	range_minimum_query(){}
	range_minimum_query(std::vector<T> &t){
		data=t;
		N=data.size();
		lg=32-__builtin_clz(N);
		block.assign((N+lg-1)/lg,std::vector<int>(lg,0));
		for(int i=0;i<N;i++){
			if(i%lg==0)
				block[i/lg][0]=i;
			block[i/lg][0]=min(i,block[i/lg][0]);
		}
		for(int j=1;j<lg;j++)
			for(int i=0;i<block.size();i++)
				block[i][j]=min(block[i][j-1],block[i+(i+(1<<(j-1))<block.size()?(1<<(j-1)):0)][j-1]);
		sblock.assign(N,0);
		std::vector<int> st;
		for(int i=0;i<block.size();i++){
			st.clear();
			for(int j=i*lg;j<N&&j<i*lg+lg;j++){
				while(!st.empty()&&data[j]<data[st.back()])
					st.pop_back();
				sblock[j]=1<<(i*lg+lg-j-1);
				if(!st.empty())
					sblock[j]|=sblock[st.back()];
				st.push_back(j);
			}
		}
		lookup.assign(1<<lg,0);
		for(int i=1,ans=lg-1;i<(1<<lg);i++){
			if(1<<(lg-ans)<=i)
				ans--;
			lookup[i]=ans;
		}
	}
	int q(int l,int r){
		if(r<l)
			swap(l,r);
		int l1=l/lg+1;
		int r1=r/lg-1;
		int ans=l;
		int t;
		if(l1<=r1){
			t=lg-lookup[r1-l1+1]-1;
			ans=min(ans,min(block[l1][t],block[r1-(1<<t)+1][t]));
		}
		t=l1*lg-1<r?l1*lg-1:r;
		ans=min(ans,lookup[sblock[t]&(~(((1<<(l-(l1*lg-lg)))-1)<<(l1*lg-l)))]+l1*lg-lg);
		t=r;
		l=l>r1*lg+lg?l:r1*lg+lg;
		ans=min(ans,lookup[sblock[t]&(~(((1<<(l-(r1*lg+lg)))-1)<<(r1*lg+(lg<<1)-l)))]+r1*lg+lg);
		return ans;
	}
};
void test(){
	int n;
	cin>>n;
	vector<int> all(n);
	fori(n)	cin>>all[i];
	range_minimum_query<int> shit(all);
	int q;
	cin>>q;
	fori(q){
		int l,r;
		cin>>l>>r;
		cout<<all[shit.q(l,r)]<<'\n';
	}
}
ll Mn[MAX][MAX]; // 1st minimum (by cols)
ll arr[MAX][MAX];
ll all[MAX*MAX];
void calc(ll n , ll m, ll a , ll b){
//	cout<<"we here "<<endl;
	fori(n){
		vector<int> now(m);
		forj(m)
			now[j] = arr[i][j];
/*		cout<<"the input "<<endl;
		forj(m)
			cout<<now[j]<<' ';
		cout<<endl;
*/		range_minimum_query<int> shit(now);	
//		cout<<"i: "<<i<<endl;
		for(ll j = m-b; j>-1; j--){
			Mn[i][j] = arr[i][shit.q(j, j+b-1)];
//			cout<<"so query "<<j<<" "<<j+b-1<<" is "<<Mn[i][j]<<endl;
		}
//		cout<<"end of "<<i<<endl;
	}
//	cout<<"we did it "<<endl;
}
 
void deal(){
	ll n, m , a,  b, g0, x, y, z;
	cin>>n>>m>>a>>b>>g0>>x>>y>>z;
	all[0] = g0;
	for(ll i =1; i<n*m; i++)
		all[i] = (all[i-1]* x + y )%z;
	fori(n)
		forj(m)
			arr[i][j] = all[i*m + j];
	calc(n,m, a ,b);
//	cout<<"we calced "<<endl;
	ll sum = 0;
	forj(m-b+1){
		vector<int> now(n);
		fori(n)
			now[i] = Mn[i][j];
		range_minimum_query<int> shit(now);
		for(ll i = n-a; i>-1; i--)
			sum+=(ll)now[shit.q(i, i+a-1)];
	}
	cout<<sum;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}