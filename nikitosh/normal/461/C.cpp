#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<map>
 
using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif
 
#define FNAME "1"

int n, q, type, p, pp, l, r, t[900000], N, cnt = 0, boo, boo2, cnt2, l2, ss, s, len;

void build (int v, int ll, int rr)
{
	if (ll == rr)
		return;
	int mm = (ll + rr) / 2;
	build(2 * v, ll, mm);
	build(2 * v + 1, mm + 1, rr);
	t[v] = t[2 * v] + t[2 * v + 1];
}

void update (int v, int ll, int rr, int index, int dlt)
{
	if (ll > index || index > rr)
		return;
	if (ll == rr && ll == index)
	{
		t[v] += dlt;
		return;
	}
	int mm = (ll + rr) / 2;
	update(2 * v, ll, mm, index, dlt);
	update(2 * v + 1, mm + 1, rr, index, dlt);
	t[v] = (t[2 * v] + t[2 * v + 1]);
}

int get (int v, int ll, int rr)
{
	if (ll > r || l > rr)
		return 0;
	if (ll >= l && rr <= r)
	{
		return t[v];
	}
	int mm = (ll + rr) / 2;
	return (get(2 * v, ll, mm) + get(2 * v + 1, mm + 1, rr));
}

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d%d", &n, &q);
	len = n;
	for (int i = 0; i < 20; i++)
		if (n <= (1 << i))
		{
			N = (1 << i);
			break;
		}	
    for (int i = N; i <= 2 * N; i++)
		t[i] = 1;
	build(1, 0, N - 1);
	cnt = 0;
	cnt2 = 0;
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d", &p);
			pp = p;
			if (boo)
			{
				pp = n - cnt2 - p;
			}
			else
			{
				pp = p + cnt;
			}
			boo2 = 0;
			if (p > len / 2)
				boo2 = 1;   
			if ((p <= len / 2 && boo == 0) || (p > len / 2 && boo == 1))
			{
				//cerr << "aa " << p << cnt2 << pp - 1 << " " << cnt << endl;
				for (int j = pp - 1; j >= cnt; j--)
				{
					update(1, 0, N - 1, pp + (pp - 1 - j), t[N + j]);
					update(1, 0, N - 1, j, -t[N + j]);
				}
				if (!boo)
				{
					cnt += p;
					len -= p;
				}
				else
				{
					//cerr << "len = " << len << " p = " << p << endl;
					cnt += len - p;
					len -= (len - p);
				}
			}
			else
			{
				//cerr << pp << " " << n - cnt2 - 1 << endl;
				for (int j = n - cnt2 - 1; j >= pp; j--)
				{
					update(1, 0, N - 1, pp - (j - pp) - 1, t[N + j]);
					update(1, 0, N - 1, j, -t[N + j]);
				}
				if (boo)
				{
					cnt2 += p;
					len -= p;
				}
				else
				{
					cnt2 += len - p;
					len -= (len - p);
				}
				//cerr << " p = " << p << " s =  " << s << endl;
				//cerr << "cnt2 = " << cnt2 << endl;
				//len -= ss;
				//boo ^= 1;
			}
			boo ^= boo2;
		}
		else
		{
			scanf("%d%d", &l, &r);
		 	if (boo == 0)
		 	{
			 	//cerr << cnt << endl;
			 	l += cnt;
			 	r += cnt - 1;
		 		//cerr << l << " ooop2s " << r << endl;
		 	}
		 	else
		 	{
		 		//cerr << cnt2 << endl;
		 		l2 = n - cnt2 - r;
		 		r = n - cnt2 - l - 1;
		 		l = l2;
		 		//cerr << l << " ooops " << r << endl;
		 	}
		 	printf("%d\n", get(1, 0, N - 1));
		}
   	} 
    return 0;
}