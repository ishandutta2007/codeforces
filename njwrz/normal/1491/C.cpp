/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
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
int n,a[5005];
struct dsu{
	int n,fa[5005];
	void init(int len){
		n=len;
		FOR(i,1,n)fa[i]=i;
	}
	int get(int x){
		RE fa[x]==x?x:(fa[x]=get(fa[x]));
	}
	void up(int x,int y){
		x=get(x);
		y=get(y);
		fa[x]=y;
	}
}d; 
void solve(){
	cin>>n;
	d.init(n+1);
	FOR(i,1,n){
		cin>>a[i];
		if(a[i]==1){
			d.up(i,i+1);
		}
	}
	int ans=0;
	rep(i,1,n){
		if(a[i]>n-i){
			ans+=a[i]-(n-i);
			a[i]=n-i;
		}
		while(a[i]>1){
			ans++;
			int now=i;
			while(now<=n){
				if(a[now]==1){
					now=d.get(now);
				}else{
					a[now]--;
					if(a[now]==1){
						d.up(now,now+1);
					}
					now+=a[now]+1;
				}
			}
		}
//		FOR(j,1,n){
//			cout<<a[j]<<' ';
//		}
//		cout<<'\n';
	}
	cout<<ans+a[n]-1<<'\n';
}
signed main(){
//	freopen("1.txt","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}