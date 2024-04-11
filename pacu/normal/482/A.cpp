#include <iostream>
using namespace std;

int main()
{
	int N,K;
	cin >> N >> K;
	int c = K/2;
	int dif = -1;
	if(K%2) dif *= -1;
	for(int i=1;i<=K;i++)
	{
		cout << c+1 << " ";
		c += i*dif;
		dif *= -1;
	}
	for(;c<N;c++)
		cout << c+1 << " ";
	return 0;
}