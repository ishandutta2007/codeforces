#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int N;
int V[100000];
int T[100000];

multiset<long long> S;

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> V[i];
	for(int j=0;j<N;j++)
		cin >> T[j];
	long long dec = 0;
	for(int i=0;i<N;i++)
	{
		S.insert(V[i] + dec);
		long long melt = 0;
		while(S.size()>0 && *S.begin() - dec <= T[i])
		{
			melt += *S.begin() - dec;
			S.erase(S.begin());
		}
		melt += S.size()*((long long)T[i]);
		dec += T[i];
		cout << melt << '\n';
	}
}