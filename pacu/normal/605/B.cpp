#include <iostream>
#include <algorithm>
using namespace std;

int w[100000],intree[100000],cid[100000];
int ans1[100000],ans2[100000];

bool cmp(int a,int b)
{
	if(w[a] == w[b])
		return intree[a]>intree[b];
	return w[a]<w[b];
}

int N,M;

int e1[100000],e2[100000];
int back,cEdges;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for(int i=0;i<M;i++)
	{
		cin >> w[i] >> intree[i];
		cid[i] = i;
	}
	sort(cid,cid+M,cmp);
	cEdges= back = 0;
	int K = 0;
	for(int i=0;i<M;i++)
	{
		int cur = cid[i];
		if(intree[cur])
		{
			ans1[cur] = K;
			K++;
			ans2[cur] = K;
			for(int j=K-2;j>=0 && cEdges<M;j--)
			{
				e1[cEdges] = j;
				e2[cEdges] = K;
				cEdges++;
			}
		}
		else
		{
			if(back == cEdges)
			{
				cout << -1 << '\n';
				return 0;
			}
			ans1[cur] = e1[back];
			ans2[cur] = e2[back];
			back++;
		}
	}
	for(int i=0;i<M;i++)
		cout << ans1[i]+1 << ' ' << ans2[i]+1 << '\n';

}