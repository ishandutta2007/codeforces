#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 3000000000LL

int N,M,L,s,t;

long long w[1000][1000];
bool wild[1000][1000];

long long d[1000][1000];
int nxt[1000][1000];
bool vis[1000];
bool insol[1000][1000];

void dijkstra(int source)
{
	for(int i=0;i<N;i++)
		d[source][i] = INF, vis[i] = 0;
	d[source][source] = 0;
	while(1)
	{
		int cur = -1;
		for(int i=0;i<N;i++)
			if(vis[i]==0 && (cur==-1 || d[source][i]<d[source][cur]))
				cur = i;
		if(cur==-1)
			break;
		vis[cur] = 1;
		for(int i=0;i<N;i++)
			if(d[source][cur]+w[cur][i] < d[source][i])
			{
				d[source][i] = d[source][cur]+w[cur][i];
				nxt[source][i] = cur;
			}
	}
}

int ex[10000],ey[10000],ew[10000];

bool isFirst(int i)
{
	int j = i;
	while(j != s)
	{
		if(wild[j][nxt[s][j]])
			return 0;
		j = nxt[s][j];
	}	
	return 1;
}

bool pos(int k)
{
	for(int i=0;i<k;i++)
		if(ew[i]==0)
			w[ex[i]][ey[i]] = w[ey[i]][ex[i]] = 1;
	for(int i=k;i<M;i++)
		if(ew[i]==0)
			w[ex[i]][ey[i]] = w[ey[i]][ex[i]] = INF;
	dijkstra(s);
	dijkstra(t);
	return d[s][t]<=L;
}

int binSearch(int low,int high)
{
	if(low==high) return low;
	if(low+1==high)
	{
		if(pos(low)) return low;
		return high;
	}
	int mid = (low+high)/2;
	if(pos(mid)) return binSearch(low,mid);
	else return binSearch(mid+1,high);
}

int main()
{
	srand(time(NULL));
	cin >> N >> M >> L >> s >> t;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			w[i][j] = INF;
	}
	int a,b,c;
	for(int i=0;i<M;i++)
	{
		cin >> a >> b >> c;
//		do
//		{
//			a = rand()%N, b = rand()%N, c = rand()%2;
//		}while(w[a][b]<INF || wild[a][b] || a==b);
//		cout << a << ' ' << b << ' ' << c << '\n';
		ex[i] = a, ey[i] = b, ew[i] = c;
		if(c>0)
		{
			w[a][b] = min(w[a][b],(long long)c);
			w[b][a] = w[a][b];
		}
		else
			wild[a][b] = wild[b][a] = 1;
	}
	dijkstra(s);
	if(d[s][t] < L)
	{
		cout << "NO\n";
		return 0;
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(wild[i][j])
				w[i][j] = 1;
	dijkstra(s);
	dijkstra(t);
	if(d[s][t] > L)
	{
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	int k = binSearch(0,M);
	if(k>0)
	{
		pos(k);
		int od = min(d[s][ex[k-1]]+d[t][ey[k-1]],d[t][ex[k-1]]+d[s][ey[k-1]]);
		w[ex[k-1]][ey[k-1]] = L-od;
	}
	else
		pos(0);
	for(int i=0;i<M;i++)
		cout << ex[i] << ' ' << ey[i] << ' ' << w[ex[i]][ey[i]] << '\n';
	return 0;
}