#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define lb long double
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
using namespace __gnu_pbds;
int n,k;
int a[(1<<20)+5];
int p[25][3];
int cnt[(1<<20)+5],ans[(1<<20)+5];
int POW(int x,int y){
	int re=1;
	while(y){
		if(y&1)re=re*x;
		x=x*x;y=y/2;
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n){
		if(!(i&1))cnt[i]=cnt[i/2]+1;
	}
	FOR(i,1,22){
		FOR(j,0,2){
			int tn=n-i,tk=k-j;gmax(tk,0ll);
			if(tn<0||tk<0||tn<tk)continue;
			int l=1,r=tn,now=0;
			FOR(t,0,tn){
				if(!now&&t>=tk)p[i][j]^=1;
				now+=cnt[r];now-=cnt[l];
				r--;l++;
			}
//			if(p[i][j])cout<<i<<' '<<j<<'\n';
		}
	}
	int maxi=1<<20;
	FOR(i,1,n){
		int now=a[i];
		FOR(j,i,n){
			if(now>=maxi)break;
			int l=i,r=j;
			int t=2;
			if(l==1)t--;
			if(r==n)t--;
//			cout<<l<<' '<<r<<' '<<r-l+t+1<<' '<<t<<' '<<now<<'\n';
			ans[now]^=p[r-l+t+1][t];
			if(a[j+1]>=20)break;
			now=now*(1<<a[j+1]);
		}
	}
	int t=maxi-1;
	while(t>=1&&ans[t]==0)t--;
	for(int i=t;i>=0;i--)cout<<ans[i];
	RE 0;
}