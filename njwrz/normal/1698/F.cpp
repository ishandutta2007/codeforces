#include<bits/stdc++.h>
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define MP make_pair
#define PB emplace_back
using namespace std;
int a[505],b[505],n;V<P<int,int> > ans;
void DO(int l,int r){
	ans.PB(MP(l,r));reverse(a+l,a+r+1);
}
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)cin>>b[i];
	if(a[1]!=b[1]){cout<<"NO\n";RE;}
	ans.clear();
	FOR(i,2,n)if(a[i]!=b[i]){
		int x=b[i-1],y=b[i];
		bool f=0;
		int it=-1;
		rep(j,i,n)if(a[j]==y&&a[j+1]==x){f=1;DO(i-1,j+1);break;}else if(a[j]==x&&a[j+1]==y)it=j;
		if(f)continue;
		if(it==-1){cout<<"NO\n";RE;}
		FOR(j,i-1,it)FOR(k,it+1,n)if(a[j]==a[k]&&!f){f=1;DO(j,k);break;}
		if(!f){cout<<"NO\n";RE;}
		rep(j,i,n)if(a[j]==y&&a[j+1]==x){DO(i-1,j+1);break;}
	}
	cout<<"YES\n";
	FOR(i,1,n)assert(a[i]==b[i]);
	cout<<ans.size()<<'\n';
	for(auto u:ans)cout<<u.F<<' '<<u.S<<'\n';
}
int main(){
	int T;cin>>T;
	while(T--)solve();
	RE 0;
}