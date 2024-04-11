#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	if((!(N%2))&&(N>2))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}