#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int N=1000005;
int T,n,e,a[200005],f[200005];
bool ban[N];
int main(){
	ban[0]=ban[1]=1;
	for(int i=2;i*i<N;++i){
		for(int j=i*i;j<N;j+=i){
			ban[j]=1;
		}
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&e);
		rep(i,1,n){
			scanf("%d",&a[i]);
		}
		per(i,n,1){
			if(i+e<=n&&a[i+e]==1){
				f[i]=f[i+e]+1;
			}else{
				f[i]=0;
			}
		}
		LL ans=0;
		per(i,n,1){
			if(a[i]==1){
				int j=i+(f[i]+1)*e;
				if(j<=n&&!ban[a[j]]){
					ans+=f[j]+1;
				}
			}else{
				if(!ban[a[i]]){
					ans+=f[i];
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}