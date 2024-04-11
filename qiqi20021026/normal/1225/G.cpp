#include<bits/stdc++.h>

using namespace std;

#define N 2200

int n,m,s,a[N],cnt[16],vis[16];
bitset<N> f[1<<16];

int main(){
	scanf("%d%d",&n,&m); s=2000;
	f[0][0]=1;
	for (int i=0;i<n;++i) scanf("%d",a+i);
	for (int i=0;i<1<<n;++i){
		for (int j=s/m;j;--j){
			f[i][j]=f[i][j]|f[i][j*m];
		}
		for (int j=0;j<n;++j){
			if (!(i>>j&1)){
				f[i|(1<<j)]|=f[i]<<a[j];
			}
		}
	}
	int now=(1<<n)-1,sum=1;
	if (!f[now][sum]){
		puts("NO");
		return 0;
	}
	puts("YES");
	while (now){
		sum*=m;
		for (int i=0;i<n;++i){
			if (now>>i&1){
				++cnt[i];
				if (sum>=a[i]&&f[now^(1<<i)][sum-a[i]]){
					now^=1<<i;
					sum-=a[i];
				}
			}
		}
	}
	for (int i=1;i<n;++i){
		int k1=0,k2=0;
		for (int j=0;j<n;++j){
			if (vis[j]) continue;
			if (cnt[j]>=cnt[k2]) k2=j;
			if (cnt[k2]>=cnt[k1]) swap(k1,k2);
		}
		printf("%d %d\n",a[k1],a[k2]);
		a[k1]+=a[k2];
		for (;a[k1]%m==0;a[k1]/=m) --cnt[k1];
		vis[k2]=1; cnt[k2]=-1;
	}
	
	return 0;
}