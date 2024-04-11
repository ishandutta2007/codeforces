#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1000];

int main()
{
	cin >> N;
	for(int i=0;i<N;i++) cin >> A[i];
	sort(A,A+N);
	int ans = 0;
	int j = 0;
	for(int i=0;i<N;i++)
	{
		while(A[i]>A[j]) j++;
		ans = max(ans,i-j);
	}
	cout << N-1-ans << '\n';
}