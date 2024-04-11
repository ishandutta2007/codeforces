#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int n,q,ord,x,y,z,bi[65536];
unsigned int f[100001][220],g[7001][220],h[7001][220]; 

const int maxn=8000;
int tot=0;
int miu[maxn],prime[maxn];
bool isPrime[maxn];
void getmiu(){
    memset(isPrime,1,sizeof(isPrime));
    miu[1]=1;
    for(int i=2;i<maxn;i++){
        if(isPrime[i]) prime[++tot]=i,miu[i]=-1;
        for(int j=1;j<=tot;j++){
            if(i*prime[j]>=maxn) break;
            isPrime[i*prime[j]]=false;
            if(i%prime[j]==0){
                miu[i*prime[j]]=0;
                break;
            }else miu[i*prime[j]]=-1*miu[i];
        }
    }
}

int main()
{
	for (int i=0; i<65536; i++)
		for (int j=0; j<16; j++)
			if (i>>j&1) bi[i]++;
	getmiu();
	for (int i=1; i<=7000; i++) if (miu[i]==-1) miu[i]=1;
	for (int i=1; i<=7000; i++)
		for (int j=1; i*j<=7000; j++) 
			if (miu[j]) g[i][(i*j)>>5]|=(1ll<<((i*j)&31));
	for (int i=1; i<=7000; i++)
		for (int j=i; j<=7000; j+=i) h[j][i>>5]|=(1ll<<(i&31));
	scanf("%d%d",&n,&q);
	while (q--)
	{
		scanf("%d%d%d",&ord,&x,&y);
		if (ord==1)
		{
			for (int j=0; j<220; j++) f[x][j]=h[y][j];
		} else
		if (ord==2)
		{
			scanf("%d",&z);
			for (int j=0; j<220; j++) f[x][j]=f[y][j]^f[z][j];
		} else
		if (ord==3)
		{
			scanf("%d",&z);
			for (int j=0; j<220; j++) f[x][j]=f[y][j]&f[z][j];
		} else
		{
			z=0;
			for (int j=0; j<220; j++) z+=bi[(g[y][j]&f[x][j])>>16]+bi[(g[y][j]&f[x][j])&65535];
			putchar((z&1)+'0');
		}
	}
	return 0;
}