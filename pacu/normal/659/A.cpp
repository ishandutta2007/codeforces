#include <iostream>
using namespace std;

int main()
{
	int N,a,b;
	cin >> N >> a >> b;
	a--;
	a = ((a+b)%N+N)%N;
	cout << a+1 << '\n';
}