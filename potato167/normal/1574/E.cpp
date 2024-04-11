#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=1167167167167167167;
const int INF=2100000000;
const ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}

ll jyo(ll x,ll y,ll z){
  ll H=y; //
       ll a=1,b=x,c=1;
       while(H>0){
         a*=2;
         if(H%a!=0){
           H-=a/2;
           c*=b;
           c%=z;
         }
        b*=b;
         b%=z;
      } //
 return c;
}



void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	ll n,m,que;
	cin>>n>>m>>que;
	vector<vector<int>> p(2,vector<int>(n));
	vector<vector<int>> q(2,vector<int>(m));
	int a1=n,b1=0;
	int a2=m,b2=0;
	int val,tmp;
	vector<int> r(2);
	map<pair<int,int>,int> M;
	rep(i,que){
		ll x,y,t;
		cin>>x>>y>>t;
		x--,y--;
		if(M.count({x,y})){
			tmp=M[{x,y}];
			val=y%2;
			if(tmp==1){
				val^=1;
			}
			p[val][x]--;
			if(p[val][x]==0){
				if(p[val^1][x]!=0) b1--;
				else a1++;
			}
			val=x%2;
			if(tmp==1){
				val^=1;
			}
			q[val][y]--;
			if(q[val][y]==0){
				if(q[val^1][y]!=0) b2--;
				else a2++;
			}
			r[tmp^(x%2)^(y%2)]--;
			M.erase({x,y});
		}
		if(t!=-1){
			tmp=t;
			M[{x,y}]=t;
			val=((y%2)^tmp);
			p[val][x]++;
			if(p[val][x]==1){
				if(p[val^1][x]==0) a1--;
				else b1++;
			}
			val=((x%2)^tmp);
			q[val][y]++;
			if(q[val][y]==1){
				if(q[val^1][y]==0) a2--;
				else b2++;
			}
			r[tmp^(x%2)^(y%2)]++;
		}
		ll ans=0;
		rep(j,2) if(r[j]==0) ans--;
		if(b1==0) ans+=jyo(2,a1,mod);
		if(b2==0) ans+=jyo(2,a2,mod);
		cout<<(ans%mod+mod)%mod<<"\n";
	}
}