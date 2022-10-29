#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<ctime>
using namespace std;

#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define gcd __gcd

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int maxn=2005;
const int mod=1e9+7;

int n,m,k;

int C[maxn][maxn];
void pre(){
	C[0][0]=1;
	for(int i=0;i<maxn;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
}

int main(){
	pre();
	scanf("%d%d%d",&n,&m,&k);
	if(k*2>=m||k*2>=n){puts("0");return 0;}
	printf("%lld\n",1ll*C[n-1][k*2]*C[m-1][k*2]%mod);
	return 0;
}