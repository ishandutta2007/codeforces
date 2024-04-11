#include <iostream>
using namespace std;

int A[100001];
int sm[100001];

int main()
{
	int N;
	cin >> N;
	sm[0] = 0;
	for(int i=0;i<N;i++)
	{
		cin >> A[i+1];
		sm[i+1] = sm[i]+A[i+1];
	}
	int ans = 0;
	for(int i=1;i<N;i++)
		if(2*sm[i] == sm[N])
			ans++;
	cout << ans << endl;
}