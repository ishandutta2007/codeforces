#include <iostream>
#include <algorithm>
using namespace std;

int N,K;
int A[100000];

bool cmp(int a,int b)
{
	return (a%10) > (b%10);
}

int main()
{
	cin >> N >> K;
	for(int i=0;i<N;i++)
		cin >> A[i];
	sort(A,A+N,cmp);
	int ans = 0;
	for(int i=0;i<N;i++)
	{
		if(A[i] == 100)
		{
			ans += 10;
			continue;
		}
		if(K >= 10-(A[i]%10))
		{
			K -= 10-(A[i]%10);
			A[i] += 10-(A[i]%10);
		}
		ans += (A[i]/10);
	}
	for(int i=0;i<N;i++)
	{
		while(A[i] < 100 && K >= 10)
		{
			A[i] += 10;
			K -= 10;
			ans++;
		}
	}
	cout << ans << '\n';
}