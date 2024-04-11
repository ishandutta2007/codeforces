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

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int maxn=2005;
const int mod=1e9+7;

int n,k;
int F[maxn][maxn];

vector<int>fac[maxn];

void add(int &a,int b){(a+=b)%=mod;}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<maxn;i++)for(int j=i;j<maxn;j+=i)fac[j].push_back(i);
//	for(int i=1;i<maxn;i++)debug(fac[i].size());
	for(int i=1;i<=n;i++){
		F[i][1]=1;
		for(int j=2;j<=k;j++)for(int h=0;h<fac[i].size();h++){
			int v=fac[i][h];
			add(F[i][j],F[v][j-1]);
		}
		//for(int j=1;j<=k;j++)printf("F[%d][%d]=%d\n",i,j,F[i][j]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)add(ans,F[i][k]);
	printf("%d\n",ans);
	return 0;
}