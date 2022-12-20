#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long N,K;
	cin >> N >> K;
	long long d = N/(2*(K+1));
	cout << d << ' ' << K*d << ' ' << N-(K+1)*d << '\n';
}