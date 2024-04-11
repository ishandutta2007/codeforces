#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <set>
#include <map>
using namespace std;

int n;
int t;

int moz[1000007];
int a;

int main()
{
	scanf("%d%d", &n, &t);
	moz[1]=1;
	for (int i=1; i<n; i++)
	{
		scanf("%d", &a);
		moz[i+a]=moz[i+a]|moz[i];
	}
	if (moz[t])
	printf("YES");
	else
	printf("NO");
	return 0;
}