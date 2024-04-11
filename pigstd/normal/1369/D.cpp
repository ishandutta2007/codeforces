#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int Mod=1e9+7;
const int M=2e6+10;
int n,k,f[M][2];

bool cmp(int a,int b){return a>b;}

int fmax(int x)
{
	if (x%3==1)return f[x][0];
	else if (x%3==2)return f[x][0];
	else return f[x][1];
}

signed main()
{
	for (int i=3;i<=20;i++)
		f[i][0]=(2*max(f[i-2][0],f[i-2][1])+max(f[i-1][0],f[i-1][1])),
		f[i][1]=(1+2*f[i-2][0]+f[i-1][0]);
	for (int i=21;i<=2e6;i++)
	{
		f[i][0]=(2*fmax(i-2)+fmax(i-1))%Mod;
		f[i][1]=(1+2*f[i-2][0]+f[i-1][0])%Mod;
	}
	WT
	{
		n=read();
		cout<<max(f[n][0],f[n][1])*4%Mod<<endl;
	}
	return 0;
}