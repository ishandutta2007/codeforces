//nathanajah's template
//28-11-2012
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <map>
#include <ctime>
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define fi first
#define se second
#define pb push_back
#define LL long long
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

int n,i;
int arr[100005];
int mini;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for (i=0;i<n;++i)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	mini=INF;
	for (i=0;i<n;++i)
	{
		int posi=upper_bound(arr,arr+n,2*arr[i])-arr;
		mini=min(mini,n-(posi-i));
	}
	printf("%d\n",mini);
}