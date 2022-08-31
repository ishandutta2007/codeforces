#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int N=100;
int n;
int a[105],b[105],d[105][10005],ans[105];

int main(){
	n=readint();
	int sum=0;
	for(int i=1;i<=n;i++) a[i]=readint(),b[i]=readint(),sum+=b[i];
	memset(d,-0x3f,sizeof(d));
	d[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=n;j>=1;j--)
			for(int k=a[i];k<=N*i;k++)
				chkmax(d[j][k],d[j-1][k-a[i]]+b[i]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=N*n;j++)
			chkmax(ans[i],min(2*j,sum+d[i][j]));
	for(int i=1;i<=n;i++) printf("%.10lf ",ans[i]/2.0);
	printf("\n");
	return 0;
}