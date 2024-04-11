#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
using namespace std;

long long A[100000];

multiset<long long> S;

int main()
{
	int N;
	long long K;
	cin >> N >> K;
	long long tot = 0;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		S.insert(A[i]);
		tot += A[i];
	}
	if(tot < K)
	{
		cout << -1 << '\n';
		return 0;
	}
	long long dif = 0;
	long long rnds;
	while(K > S.size())
	{
//		cout << S.size() << '\n';
		int cur = *S.begin();
//		cout << K << ' ' << cur << ' ' << dif << '\n';
		if(K <= S.size()*(cur - dif))
		{
			dif += K/S.size();
			K %= S.size();
		}
		else
		{
			K -= S.size()*(cur - dif);
			dif = cur;
			while(S.size() > 0 && *S.begin() <= dif)
				S.erase(S.begin());
		}
	}
//	cout << "PIE\n";
	deque<int> D;
	for(int i=0;i<N;i++)
	{
		if(A[i] > dif)
			D.push_back(i);
	}
	while(K)
	{
//		cout << D.front() << ' ' << A[D.front()] << '\n';
		if(A[D.front()]-dif == 1)
			D.pop_front();
		else
		{
			A[D.front()]--;
			D.push_back(D.front());
			D.pop_front();
		}
		K--;
	}
	while(D.size())
	{
		cout << D.front()+1 << ' ';
		D.pop_front();
	}
	cout << '\n';
}