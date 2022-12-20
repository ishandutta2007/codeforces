#include <iostream>
#include <algorithm>
using namespace std;

struct tms
{
	int a,b,s;
};

bool cmp(tms m,tms n)
{
	return m.s>n.s;
}

tms A[500000];
int used[500000];

int main()
{
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	int K = 0;
	for(int i=1;i<2*N;i++)
	{
		for(int j=0;j<i;j++)
		{
			cin >> A[K].s;
			A[K].a = i;
			A[K].b = j;
			K++;
		}
	}
	sort(A,A+K,cmp);
	for(int i=0;i<K;i++)
	{
		if(!used[A[i].a] && !used[A[i].b])
		{
			used[A[i].a] = A[i].b+1;
			used[A[i].b] = A[i].a+1;
		}
	}
	for(int i=0;i<2*N;i++)
		cout << used[i] << ' ';
	cout << '\n';
}