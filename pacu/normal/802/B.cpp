#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N,K;
int A[400000];
int loc[400000];
int nxt[400000];
int bNext[400000];

struct cmp
{
	bool operator()(int a,int b) const
	{
		if(bNext[a]==bNext[b]) return a<b;
		return bNext[a]>bNext[b];
	}
};

int main()
{
	cin >> N >> K;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		A[i]--;
	}
	for(int i=0;i<N;i++)
		loc[A[i]] = N;
	for(int i=N-1;i>=0;i--)
	{
		nxt[i] = loc[A[i]];
		loc[A[i]] = i;
	}
	set<int,cmp> S;
	int c = 0;
	for(int i=0;i<N;i++)
	{
		if(S.find(A[i]) == S.end())
		{
			if(S.size() >= K)
				S.erase(S.begin());
			c++;
			bNext[A[i]] = nxt[i];
			S.insert(A[i]);
		}
		else
		{
			S.erase(A[i]);
			bNext[A[i]] = nxt[i];
			S.insert(A[i]);
		}
	}
	cout << c << '\n';
}