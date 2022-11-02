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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int cnt[5005],g[5005][5005],p[5005];
void solve(){
	int n,m;
	cin>>n>>m;
	FILL(cnt,0);
	g[0][++cnt[0]]=1;
	int q=0,now=1;
	while(now<n){
		if(cnt[q]==(1<<q))q++;
		if(m<q)break;
		m-=q;
		g[q][++cnt[q]]=++now;
	}
	if(now<n){
		cout<<"NO\n";RE ;
	}
	if(!cnt[q])q--;
	bool f;
	do{
	f=1;
	for(int i=q;i>=1;i--){
		while(cnt[i+1]+3<=2*cnt[i]&&m){
			m--;
			g[i+1][++cnt[i+1]]=g[i][cnt[i]--];
			q=max(q,i+1);f=0;
		}
	}
	}while(m&&!f);
	if(m){
		cout<<"NO\n";RE ;
	}
	FOR(i,1,q){
		FOR(j,1,cnt[i]){
			p[g[i][j]]=g[i-1][j/2+(j&1)];
		}
	}
	cout<<"YES\n";
	FOR(i,2,n)cout<<p[i]<<' ';
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}