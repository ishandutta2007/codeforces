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

int n, m, S, b[100005], l, r, mm, ans[100005], last;
multiset <int> s;
multiset < pair <int, int> > Set;

struct st
{
	int val, cost, x;
};

st a[100005], b2[100005];

bool foo (st a, st b)
{
 	if (a.val == b.val)
  	{
  		if (a.cost == b.cost)
  			return a.x < b.x;
  		return a.cost < b.cost;
 	}
 	return a.val > b.val;
}

bool foo2 (st a, st b)
{
 	if (a.val == b.val)
  		return a.x < b.x;
  	return a.val > b.val;
}

bool check (int k)
{
	long long sum = 0;
	s.clear();
	last = 0;
	for (int j = 0; j < m; j += k)
	{
		for (int i = last; i < n; i++)
		{
			if (a[i].val < b[j])
			{
			    last = i;
				break;
			}
			s.insert(a[i].cost);
			last++;
		}
		if (s.size() == 0)
			return 0;
		sum += *(s.begin());
		s.erase(s.begin());
	}
	if (sum > S)
		return 0;
	return 1;
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &S);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b2[i].val);
		b[i] = b2[i].val;
		b2[i].x = i;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i].val);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i].cost);
		a[i].x = i;
	}
	sort(b, b + m);
	sort(b2, b2 + m, foo2);
	reverse(b, b + m);  
	sort(a, a + n, foo);
	int Min_cost = (int) 1e9 + 10;
	for (int i = 0; i < n; i++)
	{
		if (a[i].val < b[0])
			break;
		Min_cost = min(Min_cost, a[i].cost);
	}
	if (Min_cost > S)
	{
		puts("NO");
		return 0;
	}
    puts("YES");
   	l = 0;
   	r = m + 1;
   	while (r - l > 1)
   	{
   		mm = (l + r) / 2;
   		if (check(mm))
   			r = mm;
   		else
   			l = mm;
   	}                            
   	l++;
   	//printf("%d\n", l);
    last = 0;
	int l2;
	for (int j = 0; j < m; j += l)
	{
		for (int i = last; i < n; i++)
		{
			if (a[i].val < b2[j].val)
			{
			    last = i;
	 			break;
			}
			Set.insert(mp(a[i].cost, a[i].x));
			last++;
		}
		l2 = Set.begin()->second;
		for (int i = j; i < min(m, j + l); i++)
			ans[b2[i].x] = l2;
		Set.erase(Set.begin());
	}                        
    for (int i = 0; i < m; i++)
    	printf("%d ", ans[i] + 1);	
  	return 0;
}