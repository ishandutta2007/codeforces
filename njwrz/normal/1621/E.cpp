#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int a[100005],b[100005];
int len[100005];
V<int> v[100005];
int it[100005],p[100005];
bool cmp(int x,int y){
	RE b[x]*len[y]<b[y]*len[x];
}
int t[100005],tl[100005],tr[100005];
double num[100005];
void solve(){
	int n,m;
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	FOR(i,1,m)a[i]=a[i+n-m];
	n=m;
	FOR(i,1,n){
		p[i]=i;
		cin>>len[i];
		v[i].clear();
		b[i]=0;
		FOR(j,1,len[i]){
			int x;
			cin>>x;
			v[i].PB(x);
			b[i]+=x; 
		}
	}
	sort(p+1,p+n+1,cmp);
	FOR(i,1,n){
		it[p[i]]=i;
		tl[i]=a[i-1]*len[p[i]]<b[p[i]];
		tr[i]=a[i+1]*len[p[i]]<b[p[i]];
		t[i]=a[i]*len[p[i]]<b[p[i]];
		tl[i]+=tl[i-1];
		tr[i]+=tr[i-1];
		t[i]+=t[i-1];
	}
	FOR(i,1,n)num[i]=1.0*b[p[i]]/len[p[i]];
	FOR(i,1,n){
		FOR(j,1,len[i]){
			double now=1.0*(b[i]-v[i][j-1])/(len[i]-1);
//			cout<<now<<' ';
			int to=upb(num+1,num+n+1,now)-num;
			bool f=0;
			if(to>it[i]){
				to--;
				if(b[i]-v[i][j-1]<=a[to]*(len[i]-1)){
					if(!t[it[i]-1]&&t[n]==t[to]&&tl[to]==tl[it[i]]){
						f=1;
					}
				}
			}else{
				if(b[i]-v[i][j-1]<=a[to]*(len[i]-1)){
					if(!t[to-1]&&t[n]==t[it[i]]&&tr[it[i]-1]==tr[to-1]){
						f=1;
					}
				}
			}
			cout<<f;
		}
	}
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while(T--)solve();
	RE 0;
}