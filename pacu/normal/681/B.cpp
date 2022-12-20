#include <iostream>
using namespace std;

int a = 1234567;
int b = 123456;
int c = 1234;

int main()
{
	int N;
	cin >> N;
	for(int x=0;x*a<=N;x++)
		for(int y=0;x*a+y*b<=N;y++)
		{
			int rem = N - x*a - y*b;
			if(rem%c == 0)
			{
				cout << "YES\n";
				return 0;
			}
		}
	cout << "NO\n";
	return 0;
}