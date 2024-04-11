#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005,p=1000000007;
void add(int);
int qpow(int,int);
char s[maxn];
int fac[maxn],fac_inv[maxn];
int n,m,a[maxn],c[65],f[maxn],g[maxn],h[maxn],tans[65],ans[65][65];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	fac[0]=fac_inv[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=(long long)fac[i-1]*i%p;
	fac_inv[n]=qpow(fac[n],p-2);
	for(int i=n-1;i;i--)
		fac_inv[i]=(long long)fac_inv[i+1]*(i+1)%p;
	for(int i=1;i<=n;i++){
		char t=s[i];
		//scanf(" %c",&t);
		if(t<='Z')a[i]=t-'A'+1;
		else a[i]=t-'a'+1+26;
		c[a[i]]++;
	}
	int tmp=(long long)fac[n/2]*fac[n/2]%p;
	for(int i=1;i<=52;i++)
		tmp=(long long)tmp*fac_inv[c[i]]%p;
	f[0]=1;
	bool bad=false;
	for(int i=1;i<=52;i++){
		if(c[i]>n/2){
			bad=true;
			break;
		}
		if(c[i])
			for(int j=n/2;j>=c[i];j--)
				f[j]=(f[j]+f[j-c[i]])%p;
	}
	if(!bad){
		for(int i=1;i<=52;i++)
			if(c[i]){
				memcpy(g,f,sizeof(int)*(n/2+1));
				for(int k=c[i];k<=n/2;k++)
					g[k]=(g[k]-g[k-c[i]]+p)%p;
				tans[i]=g[n/2];
				for(int j=i+1;j<=52;j++)
					if(c[j]){
						memcpy(h,g,sizeof(int)*(n/2+1));
						for(int k=c[j];k<=n/2;k++)
							h[k]=(h[k]-h[k-c[j]]+p)%p;
						ans[i][j]=h[n/2];
					}
				//for(int k=n/2;k>=c[i];k--)
			}
	}
	scanf("%d",&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		x=a[x];
		y=a[y];
		if(bad){
			printf("0\n");
			continue;
		}
		if(x==y)printf("%lld\n",2ll*tans[x]*tmp%p);
		else{
			if(x>y)swap(x,y);
			printf("%lld\n",2ll*ans[x][y]*tmp%p);
		}
	}
	return 0;
}
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=(long long)a*a%p)
		if(b&1)ans=(long long)ans*a%p;
	return ans;
}