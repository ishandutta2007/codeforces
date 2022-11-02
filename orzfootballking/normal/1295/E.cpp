#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,a[200005],b[300000],l[600000],r[600000],zhi[600000],pf[600000],x[200005];
void dfs(int p,int l1,int r1,int d){
	if(l[p]>r1||l1>r[p])RE;
	if(l1<=l[p]&&r[p]<=r1){
		pf[p]=pf[p]+d;zhi[p]=zhi[p]+d;
		RE;
	}
	if(zhi[p]){
		zhi[p*2]=zhi[p*2]+zhi[p];zhi[p*2+1]=zhi[p*2+1]+zhi[p];
		pf[p*2]=pf[p*2]+zhi[p];pf[p*2+1]=pf[p*2+1]+zhi[p];
		zhi[p]=0;
	}
	dfs(p*2,l1,r1,d);dfs(p*2+1,l1,r1,d);
	pf[p]=min(pf[p*2],pf[p*2+1]);
}
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i],x[a[i]]=i;
	FOR(i,1,n)cin>>b[i];
	int ans=min(b[1],b[n]);
	int m=1;
	while(m<n)m*=2;
	FOR(i,m,m*2-1){
		l[i]=i-m+1;r[i]=l[i];
		pf[i]=pf[i-1]+b[i-m+1];
	}
	for(int i=m-1;i>=1;i--){
		l[i]=l[i*2];r[i]=r[i*2+1];
		pf[i]=min(pf[i*2],pf[i*2+1]);
	} 
	for(int i=1;i<n;i++){
		if(x[i]>1)dfs(1,1,x[i]-1,b[x[i]]);
		if(x[i]<n)dfs(1,x[i],n-1,-b[x[i]]);
		ans=min(ans,pf[1]);
	}
	cout<<ans;
	RE 0;
}