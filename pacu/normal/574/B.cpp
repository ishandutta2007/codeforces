#include <iostream>
using namespace std;

int cnt[4000];

int a[4000],b[4000];

bool rec[4000][4000];

int N,M;

int main()
{
	cin >> N >> M;
	for(int i=0;i<M;i++)
	{
		cin >> a[i] >> b[i];
		a[i]--,b[i]--;
		rec[a[i]][b[i]] = rec[b[i]][a[i]] = 1;
		cnt[a[i]]++, cnt[b[i]]++;
	}
	int best = 10000000;
	for(int j=0;j<M;j++)
		for(int i=0;i<N;i++)
		{
			if(i != a[j] && i != b[j])
				if(rec[i][a[j]] && rec[i][b[j]])
					best = min(best,cnt[a[j]]+cnt[b[j]]+cnt[i]);
		}
	if(best == 10000000)
		cout << -1 << '\n';
	else
		cout << best-6 << '\n';
}