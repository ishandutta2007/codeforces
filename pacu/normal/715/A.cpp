#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	cout << 2 << '\n';
	for(long long i=2;i<=N;i++)
		cout << i*(i+1)*(i+1)-(i-1) << '\n';
}