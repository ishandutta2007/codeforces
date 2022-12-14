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

string s, t;
int n, used[20], a[20], l; 

int foo (string r)
{
	int len = r.length();
	int b = 0;
	for (int i = 0; i < len; i++)
	{
		b *= 10;
		b += r[i] - '0';
		b %= 7;
   	}
   	return b;
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; i++)
		used[s[i] - '0']++;
	if (used[0] == n - 4)
	{
		printf("1869");
		for (int i = 0; i < n - 4; i++)
			printf("0");
		return 0;
	}
	t = "";
	for (int i = 1; i < used[1]; i++)
		t += '1';
	for (int i = 1; i < used[6]; i++)
		t += '6';
    for (int i = 1; i < used[8]; i++)
		t += '8';
    for (int i = 1; i < used[9]; i++)
		t += '9';
	for (int i = 1; i < 8; i++)
		if (i != 1 && i != 6)
			for (int j = 0; j < used[i]; j++)
				t += ('0' + i);
	for (int j = 0; j < used[0]; j++)
		t += '0';
	l = foo (t);
	a[0] = 1;
	a[1] = 6;
	a[2] = 8;
	a[3] = 9;
	cout << t;
	for (int i = 0; i < 24; i++)
	{
	    //for (int j = 0; j < 4; j++)
	    //	printf("%d", a[j]);
		//puts("");
		if ((10000 * l + a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3]) % 7 == 0)
		{
			for (int j = 0; j < 4; j++)
				printf("%d", a[j]);
			return 0;	
		}
		next_permutation(a, a + 4);
    }
	return 0;
}