#include <iostream>
using namespace std;

int main()
{
	int T,s,q;
	cin >> T >> s >> q;
	int op = 0;
	while(s < T)
		s *= q, op++;
	cout << op << '\n';
}