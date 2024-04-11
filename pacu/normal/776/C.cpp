#include <iostream>
#include <map>
using namespace std;
#define INF 10000000000000000LL

int A[100000];
int N,K;

int main()
{
	map<long long,int> M;
	cin >> N >> K;
	M[0] = 1;
	for(int i=0;i<N;i++)
		cin >> A[i];
	long long sm = 0;
	long long ans = 0;
	for(int i=0;i<N;i++)
	{
		sm += A[i];
		long long pw = 1;
		int mx = 60;
		if(K==1) mx = 1;
		if(K==-1) mx = 2;
		for(int j=1;j<=mx && pw <= INF && -pw <= INF;j++)
		{
			ans += M[sm - pw];
			pw *= K;
		}
		M[sm]++;
	}
	cout << ans << '\n';
}