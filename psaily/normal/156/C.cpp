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

const int maxv=3005;
const int maxn=105;
const int mod=1e9+7;

int cas;
char str[105];
int dp[maxn][maxv];

void add(int &a,int b){(a+=b)%=mod;}

void pre(){
	dp[0][0]=1;
	for(int i=0;i<=100;i++)for(int j=0;j<maxv;j++)if(dp[i][j]){
		for(int k=0;k<26&&k+j<maxv;k++)add(dp[i+1][j+k],dp[i][j]);
	}
}

int main(){
	pre();
	scanf("%d",&cas);
	while(cas--){
		scanf("%s",str);
		int n=strlen(str),tot=0;
		for(int i=0;i<n;i++)tot+=str[i]-'a';
		printf("%d\n",dp[n][tot]-1);
	}
	return 0;
}