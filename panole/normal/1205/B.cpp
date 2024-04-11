#include<bits/stdc++.h> 
using namespace std;
const int inf=10000000;
const int maxn = 205;  
long long a[100010],A[100010];
int n,N,m,cnt[110];
int graph[maxn][maxn], dis[maxn][maxn];
void init()  
{ 
    for(int i = 1; i <= n; ++i) 
    { 
    	for(int j = 1; j <= n; ++j)
    		graph[i][j] = dis[i][j] = inf;
    	graph[i][i] = dis[i][i] = 0;
    } 
}
void Folyd()  
{  
    int mins = inf;
    for(int k = 1; k <= n; ++k)
    {
    	for(int i = 1; i < k; ++i)
    	for(int j = i+1; j < k; ++j)
    	{
    		int tmp = dis[i][j] + graph[k][i] + graph[j][k];	
    		if(mins > tmp) mins = tmp;
    	}
    	for(int i = 1; i <= n; ++i)
    	for(int j = 1; j <= n; ++j)
    		if(dis[i][j] > dis[i][k]+dis[k][j])
    			dis[i][j] = dis[i][k]+dis[k][j];
    }
    if(mins == inf) puts("-1");
    else printf("%d\n",mins);
}

int main()  
{  
	scanf("%d",&N),n=0;
	for (int i=1; i<=N; i++) scanf("%I64d",&A[i]);
	for (int i=1; i<=N; i++) if (A[i]) a[++n]=A[i];
	memset(cnt,0,sizeof(cnt));
	if (!n) return puts("-1"),0;
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<63; j++)
			if ((a[i]>>j)&1) cnt[j]++;
	}
	for (int j=0; j<63; j++) if (cnt[j]>=3) return puts("3"),0;
	init();
	for (int i=1; i<=n; i++)
		for (int j=i+1;j<=n; j++)
			if (a[i]&a[j]) graph[i][j]=graph[j][i]=dis[i][j]=dis[j][i]=1;
	Folyd(); 
    return 0;  
}