#include <bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

typedef long long LL;
const int MN = 300005;
const int INF = 0x3f3f3f3f;

int n, m, q, k;
LL A[MN];
char str[MN];
LL f[MN][4];

int main() {
	scanf("%d", &n);
	scanf("%s",str+1);
	F(i,1,n) scanf("%lld", A+i);
	LL h=INF,a=0,r=0,d=0;
//	memset(f,INF,sizeof f);
	f[0][0]=0;
	F(i,1,n) {
		F(j,0,3)f[i][j]=f[i-1][j];
		if(str[i]=='h')f[i][0]+=A[i];
		if(str[i]=='a')f[i][1]=min(f[i-1][0],f[i][1]+A[i]);
		if(str[i]=='r')f[i][2]=min(f[i-1][1],f[i][2]+A[i]);
		if(str[i]=='d')f[i][3]=min(f[i-1][2],f[i][3]+A[i]);
//		printf("%lld %lld %lld %lld\n",f[i][0],f[i][1],f[i][2],f[i][3]);
	}
	printf("%lld\n",min(f[n][0],min(f[n][1],min(f[n][2],f[n][3]))));
	return 0;
}