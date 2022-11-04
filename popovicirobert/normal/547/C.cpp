#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define uint unsigned int
    
using namespace std;

const int MAXN = (int) 5e5;

int low[MAXN + 1];
int cnt[MAXN + 1];
   
int main() 
{
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
   	int i, j, n, q;
    ios::sync_with_stdio(false);
   	cin.tie(0), cout.tie(0);
	
	cin >> n >> q;

	vector <int> arr(n + 1);
	for(i = 1; i <= n; i++) 
	{
		cin >> arr[i];
	}

	for(i = 2; i <= MAXN; i++) 
	{
		if(low[i] == 0) 
		{
			for(j = i; j <= MAXN; j += i)
			{
				low[j] = i;
			}
		}
	}

	vector <bool> mark(n + 1);
	ll ans = 0;
	int tot = 0;

	while(q--) 
	{
		int x;
		cin >> x;

		vector <int> prime;
		int val = arr[x];
		while(val != 1) 
		{
			int cur = low[val];
			while(cur == low[val])
			{
				val /= cur;
			}
			prime.push_back(cur);
		}

		int sz = prime.size();

		function <void(int, int, int)> bkt = [&](int pos, int prd, int num)
		{
			if(pos == sz)
			{
				if(prd == 1) return ;

				if(mark[x] == 0)
				{
					if(num & 1)
						ans += cnt[prd];
					else
						ans -= cnt[prd];
					cnt[prd]++;
				}
				else 
				{
					cnt[prd]--;
					if(num & 1)
						ans -= cnt[prd];
					else
						ans += cnt[prd];
				}
			}
			else 
			{
				bkt(pos + 1, prd, num);
				bkt(pos + 1, prd * prime[pos], num + 1);
			}
		};

		bkt(0, 1, 0);

		if(mark[x] == 0)
			tot++;
		else
			tot--;
		
		mark[x] = mark[x] ^ 1;

		cout << 1LL * tot * (tot - 1) / 2 -  ans << "\n";
	}

	return 0;
}