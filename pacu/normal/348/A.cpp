#include <iostream>
using namespace std;
long long A[100000];
int main()
{
	int N;
	long long high;
	cin >> N;
	high = 0;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		high = max(high,A[i]);
	}
	long long tot = 0;
	for(int i=0;i<N;i++)
	{
		A[i] -= high;
		tot -= A[i];
	}
	long long K = ((high-tot)/(N-1));
	if((tot+K*N)<(high+K))
		K++;
	high += max((long long)0,K);
	cout << high << endl;
}