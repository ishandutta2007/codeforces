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

int boo, n, d, ind1, a[100005], b[100005], pl[100005], ans[100005];
long long x;
set <pair <int, int> > s;

long long getNextX() 
{
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB() {
    for(int i = 0; i < n; i = i + 1)
    {
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1)
    {
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1)
    {
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1)
    {
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}


int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d%d%I64d", &n, &d, &x);
	initAB();
	if (d <= 3000)
	{
		for (int i = 0; i < n; i++)
			if (b[i] == 1)
			{
				for (int j = 0; j < n - i; j++)
					ans[i + j] = max(ans[i + j], a[j]);
			}
		for (int i = 0; i < n; i++)
			printf("%d\n", ans[i]);
	}
	else
	{
		set< pair <int, int> >::iterator it;
		for (int i = 0; i < n; i++)
		{
			s.insert(mp(a[i], i));
			it = s.end();
			boo = 0;
			while (it != s.begin())
			{
				it--;
				ind1 = it->second;
				if (b[i - ind1] == 1)
				{
					printf("%d\n", a[ind1]);
					boo = 1;
					break;
				}
			}
			if (!boo)
				puts("0");
		}	
	}
    return 0;
}