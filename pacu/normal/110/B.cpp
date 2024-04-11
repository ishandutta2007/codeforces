#include <iostream>
using namespace std;

int main()
{
	const char *lt = "abcd";
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cout << lt[i%4];
	cout << endl;
}