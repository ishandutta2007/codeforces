#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
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
int len=350;
int n,m,a[100005];
int cnt[100005],to[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n){
		int t=i,r=i/len;
		r*=len;r+=len-1;
		gmin(r,n);
		while(t<=r){
			to[i]=t;t+=a[t];
			cnt[i]++;
		}
	}
	FOR(i,1,m){
		int f,x,y;
		cin>>f;
		if(!f){
			cin>>x>>y;
			int p=x/len,r=min(p*len+len-1,n),l=max(p*len,1);
			a[x]=y;
			for(int j=r;j>=l;j--){
				int nxt=j+a[j];
				if(nxt>r){
					to[j]=j;cnt[j]=1;
				}else{
					cnt[j]=cnt[nxt]+1;
					to[j]=to[nxt];
				}
			}
		}else{
			cin>>x;
			int ans=0,p=x/len,now=x,lst=x;
			while(now<=n){
				ans+=cnt[now];
				now=to[now];
				lst=now;
				now+=a[now];
			}
			cout<<lst<<' '<<ans<<'\n';
		}
	}
	RE 0;
}