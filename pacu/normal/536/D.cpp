#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 1000000000000000LL
#define MAXN 3000

int N,M;

long long eWeight[200000];
int nxt[200000];
vector<int> edges[MAXN];
bool vis[MAXN];

void dijkstra(int source,long long *ans)
{
	for(int i=0;i<MAXN;i++)
		vis[i] = 0, ans[i] = INF;
	ans[source] = 0;
	int cur;
	for(int i=0;i<N;i++)
	{
		cur = 0;
		for(int j=1;j<N;j++)
			if(!vis[j] && ((ans[j] < ans[cur]) || vis[cur]))
				cur = j;
//		cout << "Examining " << cur << " Distance " << ans[cur] << '\n';
		vis[cur] = 1;
		for(int j=0;j<edges[cur].size();j++)
			if(ans[nxt[edges[cur][j]]] > ans[cur] + eWeight[edges[cur][j]])
				ans[nxt[edges[cur][j]]] = ans[cur] + eWeight[edges[cur][j]];
	}
}

long long distA[MAXN],distB[MAXN],w[MAXN];




int acList[MAXN];	//cities sorted by A distance, break ties by B distance
long long aSum[MAXN];
int aInd[MAXN];		//indices into acList where A distance changes

int bcList[MAXN];
long long bSum[MAXN];
int bInd[MAXN];

long long dp[MAXN][MAXN][2];	//0 - A's turn ------------ 1 - B's turn
long long dpAll[MAXN][MAXN][2];

bool cmpa(int x,int y)
{
	if(distA[x] == distA[y]) return distB[x] < distB[y];
	return distA[x] < distA[y];
}

bool cmpb(int x,int y)
{
	if(distB[x] == distB[y]) return distA[x] < distA[y];
	return distB[x] < distB[y];
}

int binSearchB(int low,int high,long long bFloor)
{
	if(low == high) return low;
	if(low+1 == high)
	{
		if(distB[acList[low]] > bFloor) return low;
		return high;
	}
	int mid = (low+high)/2;
	if(distB[acList[mid]] > bFloor) return binSearchB(low,mid,bFloor);
	else return binSearchB(mid+1,high,bFloor);
}

int binSearchA(int low,int high,long long aFloor)
{
	if(low == high) return low;
	if(low+1 == high)
	{
		if(distA[bcList[low]] > aFloor) return low;
		return high;
	}
	int mid = (low+high)/2;
	if(distA[bcList[mid]] > aFloor) return binSearchA(low,mid,aFloor);
	else return binSearchA(mid+1,high,aFloor);
}

int main()
{
	int A,B;
	long long a,b,ew;
	
	cin >> N >> M;
	cin >> A >> B;
	A--,B--;
	for(int i=0;i<N;i++)
		cin >> w[i];
	for(int i=0;i<M;i++)
	{
		cin >> a >> b >> ew;
		a--,b--;
		edges[a].push_back(2*i);
		edges[b].push_back(2*i+1);
		nxt[2*i] = b, nxt[2*i+1] = a;
		eWeight[2*i] = eWeight[2*i+1] = ew;
	}
	dijkstra(A,distA);
	dijkstra(B,distB);
		
	for(int i=0;i<N;i++)
		acList[i] = bcList[i] = i;
	sort(acList,acList+N,cmpa);
	sort(bcList,bcList+N,cmpb);
	
	aSum[N-1] = w[acList[N-1]];
	for(int i=N-2;i>=0;i--)
		aSum[i] = aSum[i+1] + w[acList[i]];
		
	bSum[N-1] = w[bcList[N-1]];
	for(int i=N-2;i>=0;i--)
		bSum[i] = bSum[i+1] + w[bcList[i]];
	
	int aDif = 1;
	aInd[0] = 0;
	for(int i=1;i<N;i++)
		if(distA[acList[i]] != distA[acList[i-1]]) aInd[aDif++] = i;
	aInd[aDif] = N;
		
	int bDif = 1;
	bInd[0] = 0;
	for(int i=1;i<N;i++)
		if(distB[bcList[i]] != distB[bcList[i-1]]) bInd[bDif++] = i;
	bInd[bDif] = N;
		
	int c;
	for(int i=aDif-1;i>=0;i--)
	{
		for(int j=bDif-1;j>=0;j--)
		{
			//A's turn
			if(j>0)
				c = binSearchB(aInd[i],aInd[i+1],distB[bcList[bInd[j-1]]]);
			else
				c = aInd[i];
			dpAll[i][j][0] = max(dpAll[i+1][j][0],dp[i+1][j][1])+(aSum[c]-aSum[aInd[i+1]]);
			if(c == aInd[i+1])
				dp[i][j][0] = dp[i+1][j][0];
			else
				dp[i][j][0] = dpAll[i][j][0];
			//B's turn
			if(i>0)
				c = binSearchA(bInd[j],bInd[j+1],distA[acList[aInd[i-1]]]);
			else
				c = bInd[j];
			dpAll[i][j][1] = min(dpAll[i][j+1][1],dp[i][j+1][0])-(bSum[c]-bSum[bInd[j+1]]);
			if(c == bInd[j+1])
				dp[i][j][1] = dp[i][j+1][1];
			else
				dp[i][j][1] = dpAll[i][j][1];
//			cout << i << ' ' << j << ": " << dp[i][j][1] << '\n';
		}
	}
	if(dp[0][0][0] < 0) cout << "Cry\n";
	else if(dp[0][0][0] > 0) cout << "Break a heart\n";
	else cout << "Flowers\n";
}