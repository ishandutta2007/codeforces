#include <iostream>
#include <algorithm>
using namespace std;

int N;
int m[100000];
int num[100000];

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> m[i];
	for(int i=0;i<N;i++)
		num[i] = m[i] + 1;
	for(int i=1;i<N;i++)
		num[i] = max(num[i], num[i-1]);
	for(int i=N-2;i>=0;i--)
		num[i] = max(num[i], num[i+1] - 1);
	long long ans = 0;
	for(int i=0;i<N;i++)
		ans += num[i] - m[i] - 1;
	cout << ans << '\n';
}