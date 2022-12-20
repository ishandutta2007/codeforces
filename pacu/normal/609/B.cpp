#include <iostream>
using namespace std;

int cnt[10];

int main()
{
	int N,M,c;
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		cin >> c;
		cnt[c-1]++;
	}
	long long ans = ((long long)N)*((long long)(N-1));
	for(int i=0;i<M;i++)
		ans -= ((long long)cnt[i])*((long long)(cnt[i]-1));
	cout << ans/2LL << '\n';
}