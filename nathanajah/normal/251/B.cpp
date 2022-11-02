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

int n,k;
int q[105];
int board[105];
int s[105];
int tmp[105];
bool kika;
int i,j;

void inver()
{
	int i;
	for (i=0;i<n;++i)
		tmp[q[i]]=board[i];
	for (i=0;i<n;++i)
		board[i]=tmp[i];
}

void next()
{
	int i;
	for (i=0;i<n;++i)
		tmp[i]=board[q[i]];
	for (i=0;i<n;++i)
		board[i]=tmp[i];
}

bool cek()
{
	int i;
	for (i=0;i<n;++i)
		if (board[i]!=s[i])
			return false;
	return true;
}
void print()
{
	int i;
	for (i=0;i<n;++i)
		printf("%d ",board[i]);
	printf("\n");
}
int main()
{
	scanf("%d %d",&n,&k);
	for (i=0;i<n;++i)
	{
		scanf("%d",&q[i]);
		--q[i];
	}
	for (i=0;i<n;++i)
		scanf("%d",&s[i]);
	for (i=0;i<n;++i)
		board[i]=i+1;
	if (cek())
	{
		printf("NO\n");
		return 0;
	}
//	print();
	next();
//	print();
	if (!cek())
		kika=true;
	for (i=0;i<n;++i)
		board[i]=i+1;
	inver();
//	print();
	if (!cek())
		kika=true;
	if (!kika)
	{
		if (k==1)
			printf("YES\n");
		else
			printf("NO\n");
		return 0;
	}
	//cekmundur
	for (i=0;i<n;++i)
		board[i]=i+1;
	for (i=0;i<k;++i)
	{
		inver();
		if (cek())
		{
			if ((k-i)%2==1)
			{
				printf("YES\n");
				return 0;
			}
			else
				break;
		}
	}
	//cekmaju
	for (i=0;i<n;++i)
		board[i]=i+1;
	for (i=0;i<k;++i)
	{
		next();
		if (cek())
		{
			if ((k-i)%2==1)
			{
				printf("YES\n");
				return 0;
			}
			else
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}