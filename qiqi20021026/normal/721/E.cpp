#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define N 120000
#define INF 0x3f3f3f3f

int m,n,p,t,l[N],r[N],f[N],g[N];

int main(){
	scanf("%d%d%d%d",&m,&n,&p,&t);
	for (int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
	memset(g,INF,sizeof g); int j=0; g[0]=l[0]=r[0]=-INF;
	for (int i=1;i<=n;i++){
		f[i]=f[i-1]; g[i]=g[i-1];
		while (g[j]+t<=r[i] && j<i){
			if (f[i]<f[j]+(r[i]-max(g[j]+t,l[i]))/p || ((f[i]==f[j]+(r[i]-max(g[j]+t,l[i]))/p) && g[i]>max(g[j]+t,l[i])+(r[i]-max(g[j]+t,l[i]))/p*p)){
				f[i]=f[j]+(r[i]-max(g[j]+t,l[i]))/p;
				g[i]=max(g[j]+t,l[i])+(f[i]-f[j])*p;
			}
			j++;
		}
		j--;
	}
	printf("%d\n",f[n]);
	
	return 0;
}