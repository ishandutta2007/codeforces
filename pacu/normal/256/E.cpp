#include <cstdio>
#include <set>
using namespace std;
#define MOD 777777777
#define SEG (1<<17)

long long seg[2*SEG];

void init()
{
	for(int i=1;i<2*SEG;i++)
		seg[i] = 1;
}

void update(int i,long long val)
{
	i += SEG;
	seg[i] = val;
	for(i>>=1;i>0;i>>=1)
		seg[i] = (seg[i<<1]*seg[(i<<1)+1])%MOD;
}

long long dp[777779][4][4];	//[first][last]
int A[100000];
bool good[3][3];

int main()
{
	int N,Q;
	scanf("%d %d",&N,&Q);
	for(int i=0;i<=N;i++)
		A[i] = 0;
	A[N+1] = 0;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
			scanf("%d",&good[i][j]);
	}
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
			dp[1][i][j] = good[i][j];
		dp[1][0][i] = dp[1][i][0] = 1;
	}
	for(int l=2;l<=N;l++)
	{
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=3;j++)
			{
				dp[l][i][j] = 0;
				for(int k=1;k<=3;k++)
					dp[l][i][j] += dp[l-1][i][k]*good[k][j];
				dp[l][i][j] %= MOD;
			}
			dp[l][i][0] = (dp[l-1][i][1]+dp[l-1][i][2]+dp[l-1][i][3])%MOD;
			dp[l][0][i] = (dp[l-1][1][i]+dp[l-1][2][i]+dp[l-1][3][i])%MOD;
		}
	}
	init();
	dp[N+1][0][0] = (dp[N][1][0]+dp[N][2][0]+dp[N][3][0])%MOD;
	update(N+1,dp[N+1][0][0]);
	set<int> S;
	S.insert(0);
	S.insert(N+1);
	set<int>::iterator it;
	int v,t;
	int prev,nxt;
	long long nmult;
	for(int i=0;i<Q;i++)
	{
		scanf("%d %d",&v,&t);
		if(A[v]==t)
		{
			printf("%I64d\n",seg[1]);
			continue;
		}
		if(t == 0)
		{
			it = S.find(v);
			it--;
			prev = *it;
			it++,it++;
			nxt = *it;
			update(v,1);
			nmult = 0;
			update(nxt,dp[nxt-prev][A[prev]][A[nxt]]);
			S.erase(v);
		}
		else
		{
			S.insert(v);
			it = S.find(v);
			it--;
			prev = *it;
			it++,it++;
			nxt = *it;
			update(v,dp[v-prev][A[prev]][t]);
			update(nxt,dp[nxt-v][t][A[nxt]]);
		}
		A[v] = t;
		printf("%I64d\n",seg[1]);
	}
	return 0;
}