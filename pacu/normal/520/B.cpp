#include <iostream>
using namespace std;

int num[500000];
int dist[500000];
int cur,len;
int best[500000];

int main()
{
	for(int i=0;i<500000;i++)
		best[i] = 500000;
	int N,M;
	cin >> N >> M;
	cur = 0;
	len = 1;
	num[0] = N;
	dist[0] = 0;
	best[0] = 0;
	while(num[cur] != M)
	{
		if((num[cur] < M)&&((1+dist[cur])<best[2*num[cur]]))
		{
			num[len] = 2*num[cur];
			dist[len]  = 1 + dist[cur];
			best[2*num[cur]] = 1+dist[cur];
			len++;
		}
		if((num[cur] > 1)&&((1+dist[cur])<best[num[cur]-1]))
		{
			num[len] = num[cur]-1;
			dist[len] = 1 + dist[cur];
			best[num[cur]-1] = 1+dist[cur];
			len++;
		}
		cur++;
	}
	cout << dist[cur] << endl;
	return 0;
}