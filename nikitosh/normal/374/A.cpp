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

int n, m, i, j, a, b, ans1, ans2, ans3, ans4, l1, l2;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d%d%d%d%d", &n, &m, &i, &j, &a, &b);
	l1 = i - 1;
	l2 = j - 1;
	ans1 = ans2 = ans3 = ans4 = (int) 1e9;
	if (l1 % a == 0 && l2 % b == 0 && (l1 / a) % 2 == (l2 / b) % 2)
		ans1 = max(l1 / a, l2 / b);
	if (ans1 != 0 && ((i - a <= 0 && i + a > n) || (j - b <= 0 && j + b > m)))
		ans1 = (int) 1e9;
	l1 = i - 1;
	l2 = m - j;
	if (l1 % a == 0 && l2 % b == 0 && (l1 / a) % 2 == (l2 / b) % 2)
		ans2 = max(l1 / a, l2 / b);
	if (ans2 != 0 && ((i - a <= 0 && i + a > n) || (j - b <= 0 && j + b > m)))
		ans2 = (int) 1e9;
	l1 = n - i;
	l2 = j - 1;
	if (l1 % a == 0 && l2 % b == 0 && (l1 / a) % 2 == (l2 / b) % 2)
		ans3 = max(l1 / a, l2 / b);
	if (ans3 != 0 && ((i - a <= 0 && i + a > n) || (j - b <= 0 && j + b > m)))
		ans3 = (int) 1e9;
	l1 = n - i;
	l2 = m - j;
	if (l1 % a == 0 && l2 % b == 0 && (l1 / a) % 2 == (l2 / b) % 2)
		ans4 = max(l1 / a, l2 / b);
	if (ans4 != 0 && ((i - a <= 0 && i + a > n) || (j - b <= 0 && j + b > m)))
		ans4 = (int) 1e9;
	n = min(min(min(ans1, ans2), ans3), ans4);
	if (n == (int) 1e9)
		puts("Poor Inna and pony!");
	else
		printf("%d\n", n);	
	return 0;
}