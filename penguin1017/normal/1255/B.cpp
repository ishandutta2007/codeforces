#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const int N=1e5+9;
int a[N],ord[N];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		ll ans=0;
		scanf("%d%d",&n,&m);
		rep(i,1,n+1)scanf("%d",&a[i]),ord[i]=i,ans+=a[i]<<1;
		if(m<n||n==2){
			printf("-1\n");
			continue;
		}
		sort(ord+1,ord+1+n,cmp);
		m-=n;
		ans+=1ll*m*(a[ord[1]]+a[ord[2]]);
		printf("%lld\n",ans);
		rep(i,1,n)printf("%d %d\n",i,i+1);
		printf("%d %d\n",n,1);
		rep(i,0,m)printf("%d %d",ord[1],ord[2]);
	}
}