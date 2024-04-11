#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cassert>

using namespace std;

#define FNAME ""
#define FILE 0

#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define LD long double

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

int n, m, a[3000005], sz, N, k, b[3000005], t[3000005], del, l, boo;

void erase(int v, int ll, int rr, int k)
{
	if (ll == rr && k != 1)
		while(1)
			k = 1;
	if (ll == rr)
	{
		l = ll + N;
		t[l]--;		
		return;
	}
	int mm = (ll + rr) / 2;
	if (t[2 * v] >= k)
		erase(2 * v, ll, mm, k);
	else
		erase(2 * v + 1, mm + 1, rr, k - t[2 * v]);
	t[v] = t[2 * v] + t[2 * v + 1]; 
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 30; i++)
		if ((1 << i) > (int) 1e6)
		{
			sz = 1 << i;
			break;
		}
	N = sz;
	for (int i = 0; i < n; i++)
	{
    	scanf("%d", &k);
    	if (k >= 0)
    	{
    		l = sz;
    		b[sz++] = k;
    	    while (l > 0)
    	    {
    	    	t[l]++;
    	    	l /= 2;
    		}
    	}
    	else
    	{
    		int tmp_del = 0;
    		for (int j = 0; j < m; j++)
    		{
    			if ((a[j] - tmp_del) + del > (sz - N))
    				break;
    			del++;
                erase(1, 0, N - 1, a[j] - tmp_del);
                tmp_del++;
    		}
    		
    	}
        /*for (int i = N; i < 3000000; i++)
    	if (t[i] == 1)
    		printf("%d", b[i]);
    	puts("");*/
    }
    for (int i = N; i < 3000000; i++)
    	if (t[i] == 1)
    	{
    		printf("%d", b[i]);
			boo = 1;
		}
	if (boo == 0)
		puts("Poor stack!");
	return 0;
}