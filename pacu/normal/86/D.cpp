#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define BSIZE 450


struct query
{
	int l,r,cid;
	long long a;
};

bool cmp(query a,query b)
{
	if((a.l/BSIZE)==(b.l/BSIZE))
		return a.r<b.r;
	return (a.l/BSIZE) < (b.l/BSIZE);
}

bool idcmp(query a,query b)
{
	return a.cid<b.cid;
}

int cOcc[1000001];
long long ans;

void add(int v)
{
	ans += (2*cOcc[v]+1)*((long long)v);
	cOcc[v]++;
}

void rem(int v)
{
	ans -= (2*cOcc[v]-1)*((long long)v);
	cOcc[v]--;
}

int A[200000];
query B[200000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,T;
	cin >> N >> T;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=0;i<T;i++)
	{
		cin >> B[i].l >> B[i].r;
		B[i].l--,B[i].r--;
		B[i].cid = i;
	}
	sort(B,B+T,cmp);
	int low = 0;
	int high = 0;
	ans = A[0];
	cOcc[A[0]] = 1;
	for(int i=0;i<T;i++)
	{
		while(low>B[i].l)
		{
			low--;
			add(A[low]);
		}
		while(low<B[i].l)
		{
			rem(A[low]);
			low++;
		}
		while(high<B[i].r)
		{
			high++;
			add(A[high]);
		}
		while(high>B[i].r)
		{
			rem(A[high]);
			high--;
		}
		B[i].a = ans;
	}
	sort(B,B+T,idcmp);
	for(int i=0;i<T;i++)
		cout << B[i].a << endl;
	return 0;
}