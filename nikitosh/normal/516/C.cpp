#include <bits/stdc++.h> 

using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;

#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#define FNAME "1"

const int Maxn = 200005;

int n, m;
LL d[Maxn], h[Maxn], sum[Maxn]; 
pair <pair <LL, LL>, pair <LL, LL> > Min[Maxn][20], Max[Maxn][20];
pair <LL, LL> a1[10], a2[10], a[Maxn], b[Maxn];
int Log[Maxn + 5];

LL get (int k, int l)
{
	int len = l - k + 1;
	int lg = Log[len];
	int sz1 = 0;
	a1[sz1++] = Min[k][lg].first;
	a1[sz1++] = Min[k][lg].second;
	a1[sz1++] = Min[l - (1 << lg) + 1][lg].first;
	a1[sz1++] = Min[l - (1 << lg) + 1][lg].second;
	sort(a1, a1 + sz1);
	sz1 = unique(a1, a1 + sz1) - a1;
	//printf("%I64d %I64d\n", a1[0].first, a1[0].second);

	int sz2 = 0;
	a2[sz2++] = Max[k][lg].first;
	a2[sz2++] = Max[k][lg].second;
	a2[sz2++] = Max[l - (1 << lg) + 1][lg].first;
	a2[sz2++] = Max[l - (1 << lg) + 1][lg].second;
	sort(a2, a2 + sz2);
	sz2 = unique(a2, a2 + sz2) - a2;
	reverse(a2, a2 + sz2);
	if (a1[0].second != a2[0].second)
		return a2[0].first - a1[0].first;
	return max(a2[0].first - a1[1].first, a2[1].first - a1[0].first);
}

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	for (int i = 1; i < Maxn; i++)
	{	
	    int s = i;
		while (s > 1)
		{
			Log[i]++;
			s >>= 1;
		}
	}
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &d[i]);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &h[i]);
	for (int i = 0; i < n; i++)
	{
		d[i + n] = d[i];
		h[i + n] = h[i];
	}
	for (int i = 0; i < 2 * n; i++)
	{
		sum[i + 1] = sum[i] + d[i];
		a[i] = mp(sum[i] + 2 * h[i], i);
		b[i] = mp(sum[i] - 2 * h[i], i);
	}
	for (int i = 0; i < 2 * n - 1; i++)
	{
		Min[i][1] = mp(min(b[i], b[i + 1]), max(b[i], b[i + 1]));
		Max[i][1] = mp(max(a[i], a[i + 1]), min(a[i], a[i + 1]));
	}
	for (int i = 2; i < 20; i++)
	{
		for (int j = 0; j < 2 * n; j++)
		{
			if (j + (1 << i) > 2 * n)
				break;
			if (Min[j][i - 1].first < Min[j + (1 << (i - 1))][i - 1].first)
			{
				Min[j][i].first = Min[j][i - 1].first;
				Min[j][i].second = min(Min[j][i - 1].second, Min[j + (1 << (i - 1))][i - 1].first);
			}	
			else
			{
				Min[j][i].first = Min[j + (1 << (i - 1))][i - 1].first;
				Min[j][i].second = min(Min[j][i - 1].first, Min[j + (1 << (i - 1))][i - 1].second);
			}	
			if (Max[j][i - 1].first > Max[j + (1 << (i - 1))][i - 1].first)
			{
				Max[j][i].first = Max[j][i - 1].first;
				Max[j][i].second = max(Max[j][i - 1].second, Max[j + (1 << (i - 1))][i - 1].first);
			}	
			else
			{
				Max[j][i].first = Max[j + (1 << (i - 1))][i - 1].first;
				Max[j][i].second = max(Max[j][i - 1].first, Max[j + (1 << (i - 1))][i - 1].second);
			}	
		}
	}
	for (int i = 0; i < m; i++)
	{
		int p, q, k, l;
		scanf("%d%d", &k, &l);
		k--;
		l--;
		if (k > l)
		{
			p = l + 1;
			q = k - 1;
		}
		else
		{          
			p = l + 1;
			q = n + k - 1;
		}
		printf("%I64d\n", get(p, q));
	}
	return 0;
}