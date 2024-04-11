#include <iostream>
using namespace std;

struct Node
{
	Node *a[2];
	Node()
	{
		a[0] = a[1] = NULL;
	}
};

long long A[100000];
long long B[100001];
long long C[100001];

long long slow(int N)
{
	long long b = 0;
	for(int i=0;i<=N;i++)
		for(int j=0;j<=N;j++)
			b = max(b,B[i]^C[j]);
	return b;
}

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	Node root;
	Node *cur;
	long long b;
	B[0] = 0;
	for(int i=0;i<N;i++)
		B[i+1] = B[i]^A[i];
	C[N] = 0;
	for(int i=N-1;i>=0;i--)
		C[i] = C[i+1]^A[i];
	for(int i=0;i<=N;i++)
	{
		cur = &root;
		for(int j=39;j>=0;j--)
		{
			b = (B[i]&(1LL<<j))!=0;
			if(cur->a[b] == NULL)
				cur->a[b] = new Node();
			cur = cur->a[b];
		}
	}
	long long best = 0;
	long long curAns;
	for(int i=0;i<=N;i++)
	{
		cur = &root;
		curAns = 0;
		for(int j=39;j>=0;j--)
		{
			b = (C[i]&(1LL<<j))==0;
			if(cur->a[b] == NULL)
				b = 1-b;
			curAns += (b<<j);
			cur = cur->a[b];
		}
		curAns ^= C[i];
		best = max(best,curAns);
	}
	cout << best << endl;
//	cout << slow(N) << endl;
}