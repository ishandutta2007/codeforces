#include <iostream>
using namespace std;

int main()
{
	int N,K,T;
	cin >> N >> K >> T;
	int p = N*K*T;
	for(int i=0;i<N;i++)
	{
		if((p-100*K)>=0)
		{
			cout << K << " ";
			p -= 100*K;
		}
		else
		{
			cout << p/100 << " ";
			p = p - 100*(p/100);
		}
	}
	cout << endl;
}