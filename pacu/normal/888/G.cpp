#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[200000];

int ch[7000000][2];
int nodes;

void clear()
{
	while(nodes>=1)
	{
		ch[nodes][0] =ch[nodes][1] = 0;
		nodes--;
	}
	nodes = 1;
}

void insert(int v)
{
	int i = 1;
	for(int j=29;j>=0;j--)
	{
		if(!ch[i][(v>>j)&1])
			ch[i][(v>>j)&1] = ++nodes;
		i = ch[i][(v>>j)&1];
	}
}

int getMinXOR(int v)
{
	int i = 1;
	int ans = 0;
	for(int j=29;j>=0;j--)
	{
		if(ch[i][(v>>j)&1])
			i = ch[i][(v>>j)&1];
		else
		{
			i = ch[i][((v>>j)&1)^1];
			ans += (1<<j);
		}
	}
	return ans;
}

long long tot;

void solve(int a,int b,int i)
{
	if(i<0) return;
	if(((A[a]^A[b-1]) & (1<<i)) == 0)
	{
		solve(a,b,i-1);
		return;
	}
	int mid = a;
	while(((A[a]^A[mid]) & (1<<i)) == 0)
		mid++;
	clear();
	for(int j=mid;j<b;j++)
		insert(A[j]);
	int ans = (1<<30);
	for(int j=a;j<mid;j++)
		ans = min(ans,getMinXOR(A[j]));
	tot += ans;
	solve(a,mid,i-1);
	solve(mid,b,i-1);
}

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	sort(A,A+N);
	clear();
	solve(0,N,29);
	cout << tot << '\n';
}