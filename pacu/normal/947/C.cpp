#include <iostream>
#include <algorithm>
using namespace std;

int ch[10000000][2];
int sz[10000000];
int M;

int A[300000];

int main()
{
	int N,a;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	M = 2;
	for(int i=0;i<N;i++)
	{
		cin >> a;
		int cur = 1;
		for(int j=29;j>=0;j--)
		{
			if(!ch[cur][(a>>j)&1])
				ch[cur][(a>>j)&1] = M++;
			cur = ch[cur][(a>>j)&1];
			sz[cur]++;
		}
	}
	for(int i=0;i<N;i++)
	{
		a = A[i];
		int v = 0;
		int cur = 1;
		for(int j=29;j>=0;j--)
		{
			if(sz[ch[cur][(a>>j)&1]])
			{
				cur = ch[cur][(a>>j)&1];
			}
			else
			{
				v += (1<<j);
				cur = ch[cur][((a>>j)&1)^1];
			}
			sz[cur]--;
		}
		cout << v << ' ';
	}
	cout << '\n';
}