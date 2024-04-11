#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct vertex
{
	int id,degree,xor;
};

vertex A[1<<16];

struct cmp
{
	bool operator()(int a,int b)
	{
		if(A[a].degree == A[b].degree)
			return a<b;
		return A[a].degree < A[b].degree;
	}
};

int main()
{
	int N;
	cin >> N;
	int M = 0;
	for(int i=0;i<N;i++)
	{
		A[i].id = i;
		cin >> A[i].degree >> A[i].xor;
		M += A[i].degree;
	}
	M /= 2;
	set<int,cmp> S;
	for(int i=0;i<N;i++)
		if(A[i].degree)
			S.insert(i);
	cout << M << endl;
	for(int i=0;i<M;i++)
	{
		int cur = *S.begin();
		S.erase(S.begin());
		if(!A[cur].degree)
		{
			i--;
			continue;
		}
		int par = *S.find(A[cur].xor);
		cout << cur << " " << par << endl;
		S.erase(par);
		A[par].degree--;
		A[par].xor ^= cur;
		S.insert(par);
	}
}