#include <iostream>
#include <map>
using namespace std;

int nxt[4000000][2];
int sm[4000000];
int C = 1;

map<int,int> M;

int main()
{
	int Q;
	cin >> Q;
	int a,t,x;
	for(int i=0;i<Q;i++)
	{
		cin >> a >> t >> x;
		if(M.find(x) == M.end())
			M[x] = C++;
		int cur = M[x];
		if(a==1)
		{
			for(int i=30;i>=0;i--)
			{
				int p = (t >= (1LL<<i));
				if(nxt[cur][p]==0) nxt[cur][p] = C++;
				cur = nxt[cur][p];
				sm[cur]++;
				if(p) t -= (1LL<<i);
			}
		}
		else if(a==2)
		{
			for(int i=30;i>=0;i--)
			{
				int p = (t >= (1LL<<i));
				if(nxt[cur][p]==0) nxt[cur][p] = C++;
				cur = nxt[cur][p];
				sm[cur]--;
				if(p) t -= (1LL<<i);
			}			
		}
		else
		{
			int ans = 0;
			for(int i=30;i>=0;i--)
			{
				int p = (t >= (1LL<<i));
				if(nxt[cur][p]==0) nxt[cur][p] = C++;
				if(p)
				{
					ans += sm[nxt[cur][0]];
					t -= (1LL<<i);
				}
				cur = nxt[cur][p];
			}
			ans += sm[cur];
			cout << ans << '\n';
		}
	}
}