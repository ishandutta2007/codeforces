#include <iostream>
using namespace std;

int cnt[1000000],a[1000000],b[1000000];

int A[100000];
int main()
{
	int N;
	cin >> N;
	for(int i=0;i<1000000;i++)
		a[i] = 1000000, b[i] = -1000000;
	int high = 0;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		A[i]--;
		cnt[A[i]]++;
		high = max(high,cnt[A[i]]);
		a[A[i]] = min(a[A[i]],i);
		b[A[i]] = max(b[A[i]],i);
	}
	int best = 1000000;
	int bestl,bestr;
	for(int i=0;i<1000000;i++)
	{
		if(cnt[i] == high)
		{
			if(b[i]-a[i] < best)
			{
				best = b[i]-a[i];
				bestl = a[i];
				bestr = b[i];
			}
		}
	}
	cout << bestl+1 << " " << bestr+1 << '\n';
}