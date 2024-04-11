#include <iostream>
using namespace std;

int ans[] = {1,0,0,1,0,1,0,1,1,1,0,0,1,0,1,0};

int main()
{
	int N;
	cin >> N;
	cout << ans[N-1] << '\n';
}