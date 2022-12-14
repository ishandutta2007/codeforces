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

int n, a[100005], l1, l2, sz, p1, p2, p3, m[5];
vector <int> v, temp;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	v.pb(-1);
	for (int i = 0; i < n; i++)
		if (a[i] == 0)
			v.pb(i);
	v.pb(n);
	for (int i = 0; i < (int) v.size() - 1; i++)
	{
		l1 = v[i];
		l2 = v[i + 1];
		temp.clear();
		for (int i = l1 + 1; i < l2; i++)
			temp.pb(a[i]);
		sort(temp.begin(), temp.end());
		sz = (int) temp.size(); 
		if (sz == 0)
		{
			if (l2 == n)
				return 0;
			puts("0");
			continue;
        }
        if (sz == 1)
        {
        	puts("pushStack");
            if (l2 == n)
            	return 0;
        	puts("1 popStack");
          	continue;
        }
		if (sz == 2)
        {
        	puts("pushStack");
        	puts("pushQueue");
            if (l2 == n)
            	return 0;
        	puts("2 popStack popQueue");
        	continue;
        }
        p1 = temp[sz - 1];
        p2 = temp[sz - 2];
        p3 = temp[sz - 3];
        for (int i = l1 + 1; i < l2; i++)
        	if (a[i] == p1)
        	{
        		m[0] = i;
        		break;
        	}
        for (int i = l1 + 1; i < l2; i++)
        	if (a[i] == p2 && i != m[0])
        	{
        		m[1] = i;
        		break;
        	}
        for (int i = l1 + 1; i < l2; i++)
        	if (a[i] == p3 && i != m[0] && i != m[1])
        	{
        		m[2] = i;
        		break;
        	}
		sort(m, m + 3);
		for (int i = l1 + 1; i < m[0]; i++)
			puts("pushStack");      	
		puts("pushQueue");
		for (int i = m[0] + 1; i < m[1]; i++)
			puts("pushStack");      	
		puts("pushFront");      	
		for (int i = m[1] + 1; i <= m[2]; i++)
			puts("pushStack");      	
		for (int i = m[2] + 1; i < l2; i++)
			puts("pushQueue");
        if (l2 == n)
          	return 0;
		puts("3 popStack popQueue popFront");
	}
	return 0;
}