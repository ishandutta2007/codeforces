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
#define PB push_back
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int a[100005],b[100005],s[100005],t[100005];
bool f[100005];
bool cmp(int x,int y){
	if(b[x]!=b[y]){
		RE b[x]>b[y];
	}else RE a[x]<a[y];
}
bool cc(int x,int y){
	if(a[x]!=a[y]){
		RE a[x]>a[y];
	}else RE b[x]>b[y];
}
bool cd(int x,int y){
	if(b[x]!=b[y]){
		RE b[x]>b[y];
	}else RE a[x]<=a[y];
}
P<int,int> cur;
int ans;
bool cm(int x,int y){
	RE b[x]>b[y];
}
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,p,k;
	cin>>n>>p>>k;
	FOR(i,1,n){
		cin>>a[i]>>b[i];
	}
	FOR(i,1,n)s[i]=i;
	sort(s+1,s+n+1,cmp);
	FOR(i,1,n-p+k)t[i]=s[i];
	sort(t+1,t+n-p+k+1,cc);
	V<int> ans;
	int maxi=t[1];
	FOR(i,2,k){
		if(cd(maxi,t[i]))maxi=t[i];
	}
	FOR(i,1,k)f[t[i]]=1;
	V<int> el;
	FOR(i,1,n)if(!f[i]&&cd(maxi,i))el.PB(i);
	sort(ALL(el),cm);
	FOR(i,1,k){
		ans.PB(t[i]);
	}
	rep(i,0,p-k)ans.PB(el[i]);
	sort(ALL(ans));
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
	cout<<'\n';
	RE 0;
}