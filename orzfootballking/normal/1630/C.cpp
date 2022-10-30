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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,a[200005],l[200005],r[200005];
P<int,int> p[200005];
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>a[i],l[i]=r[i]=0;
	FOR(i,1,n){
		r[a[i]]=i;
		if(!l[a[i]])l[a[i]]=i;
	}
	int ans=0;
	int m=0;
	int cnt=0;
	FOR(i,1,n)if(l[i]&&l[i]!=r[i])p[++cnt]=MP(l[i],r[i]);
	sort(p+1,p+cnt+1);
	V<int> ed;
	FOR(i,1,cnt){
		if(p[i].S>m){
			if(p[i].F<m){
				ans+=p[i].S-m-1;
				if(!ed.empty()){
					int t=ed.back();
					ed.pop_back();
					while(!ed.empty()&&ed.back()>=p[i].F)t=ed.back(),ed.pop_back(),ans++;
					ed.PB(t);
				}
				ed.PB(p[i].S);
			}else ans+=p[i].S-p[i].F-1,ed.PB(p[i].S);
			m=p[i].S;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	T=1;
	while(T--)solve();
	RE 0;
}