#include <iostream>
using namespace std;

int F[3];

int main()
{
	int N,a,b,c;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> a >> b >> c;
		F[0] += a;
		F[1] += b;
		F[2] += c;
	}
	if(F[0]||F[1]||F[2])
		cout << "NO\n";
	else
		cout << "YES\n";
}