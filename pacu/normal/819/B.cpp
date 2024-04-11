#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int N;
int p[1000000];
int loc[1000000];
long long val[1000000];
long long inc[1000000];
int numSwap[1000000];

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&p[i]);
		p[i]--;
		loc[p[i]] = i;
	}
	long long cur = 0;
	int numBef = 0;
	for(int i=0;i<N;i++)
	{
		int k = (p[i]+N-i)%N;
		numSwap[k]++;
		cur += abs(p[i]-i);
		if(p[i] >= i)
			numBef++;
	}
	long long cinc = 0;
	long long cmin = 1000000000000000000LL;
	int cid = 0;
	for(int i=0;i<N;i++)
	{
		if(cur < cmin)
			cmin = cur, cid = i;
		numBef -= numSwap[i];
		cur += N-1-2*numBef;
		cur += p[N-1-i];
		cur -= N-1-p[N-1-i];
		numBef++;
	}
	cout << cmin << ' ' << cid << '\n';
}