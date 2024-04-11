#include <iostream>
using namespace std;

int n,k;
int main()
{
	cin >> n >> k;
	cout << n - n%k + k << '\n';
}