#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>

using namespace std;

#define long long long
#define fi first
#define se second
typedef pair<int,int> ii;
typedef 


deque<int> deq;

int n;
long c, d;
long A[1000003];
char C[1000003];

int main()
{
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("input.in", "r", stdin);

	scanf("%d %I64d %I64d\n", &n, &c, &d);
	for(int i = 1; i <= n; i++)
	{
		char c;
		long t;
		scanf("%I64d %c\n", &A[i], &C[i]);
	}
	long end;
	scanf("%I64d", &end);


	long totres = 0;
	long res = (d*n);
	for(int i = n; i >= 1; i--)
	{
		if(C[i] != C[i-1])
		{
			totres += (end-A[i])*c;
			end = A[i];
		}
		else
			totres += min((end-A[i])*c,d);
		res = min(res, totres+(i-1)*d);
	}
	printf("%I64d\n", res);
}