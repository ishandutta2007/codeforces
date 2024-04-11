#include <iostream>
using namespace std;

long long dist[200000];
int cnt[200000];
int N,M;

int tmp[200000];

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> dist[i];
	for(int i=N-1;i>=0;i--)
		dist[i] -= dist[0];
	cin >> M;
	int c;
	for(int i=0;i<M;i++)
	{
		cin >> c;
		cnt[c-1]++;
	}
	if(cnt[0] == 0 && cnt[N-1] == 0)
	{
		int ans = 0;
		for(int i=1;i<N;i++)
			if(cnt[i] && cnt[i-1])
				ans += dist[i] - dist[i-1];
		cout << ans << '\n';
		return 0;
	}
	if(cnt[0] > cnt[N-1])
	{
		// 0 - 0
		long long d = 2*cnt[N-1]*dist[N-1];
		M -= (N-1)*2*cnt[N-1];
		for(int i=0;i<N;i++)
			tmp[i] = cnt[i];
		for(int i=1;i<N-1;i++)
			tmp[i] -= 2*tmp[N-1];
		tmp[N-1] = 0;
		tmp[0] = 1;
		long long ans = -1;
		long long cur;
		int dif = 0;
		for(int i=1;i<N;i++)
			dif += (tmp[i]!=tmp[i-1]);
		for(int i=1;i<=N-1;i++)
		{
			if(dif == 1)
			{
				cur = d + dist[i-1] + dist[M - i];
				if(ans == -1) ans = cur;
				if(ans != cur)
				{
					cout << -1 << '\n';
					return 0;
				}
			}
			dif -= (tmp[i]!=tmp[i-1]);
			dif -= (tmp[i]!=tmp[i+1]);
			if(!tmp[i]) break;
			tmp[i]--;
			dif += (tmp[i]!=tmp[i-1]);
			dif += (tmp[i]!=tmp[i+1]);
		}
		cout << ans << '\n';
	}
	else if(cnt[0] < cnt[N-1])
	{
		// 5 - 5
		long long d = 2*cnt[0]*dist[N-1];
		M -= (N-1)*2*cnt[0];
		for(int i=0;i<N;i++)
			tmp[i] = cnt[i];
		for(int i=1;i<N-1;i++)
			tmp[i] -= 2*tmp[0];
		tmp[0] = 0;
		tmp[N-1] = 1;
		long long ans = -1;
		long long cur;
		int dif = 0;
		for(int i=1;i<N;i++)
			dif += (tmp[i]!=tmp[i-1]);
		for(int i=N-2;i>=0;i--)
		{
			if(dif == 1)
			{
				cur = d + (dist[N-1]-dist[i+1]) + (dist[N-1]-dist[N - 1 - (M - (N-1-i))]);
				if(ans == -1) ans = cur;
				if(ans != cur)
				{
					cout << -1 << '\n';
					return 0;
				}
			}
			dif -= (tmp[i]!=tmp[i-1]);
			dif -= (tmp[i]!=tmp[i+1]);
			if(!tmp[i]) break;
			tmp[i]--;
			dif += (tmp[i]!=tmp[i-1]);
			dif += (tmp[i]!=tmp[i+1]);
		}
		cout << ans << '\n';		
	}
	else
	{
		// 0 - 5
		long long d = (2*cnt[0]-1)*dist[N-1];
		M -= (N-1)*(2*cnt[0]-1);
		for(int i=0;i<N;i++)
			tmp[i] = cnt[i];
		for(int i=1;i<N-1;i++)
			tmp[i] -= (2*tmp[0]-1);
		tmp[N-1] = 1;
		tmp[0] = 0;
		long long ans = -1;
		long long cur;
		int dif = 0;
		for(int i=1;i<N;i++)
			dif += (tmp[i]!=tmp[i-1]);
		for(int i=1;i<=N-1;i++)
		{
			if(dif == 1)
			{
				cur = d + dist[i-1] + (dist[N-1]-dist[N - 1 - (M - i)]);
				if(ans == -1) ans = cur;
				if(ans != cur)
				{
					cout << -1 << '\n';
					return 0;
				}
			}
			dif -= (tmp[i]!=tmp[i-1]);
			dif -= (tmp[i]!=tmp[i+1]);
			if(!tmp[i]) break;
			tmp[i]--;
			dif += (tmp[i]!=tmp[i-1]);
			dif += (tmp[i]!=tmp[i+1]);
		}
		cout << ans << '\n';	
	}
}