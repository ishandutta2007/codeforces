#include <iostream>
using namespace std;

int a,b,c;
int N;
int x[100000];

int main()
{
	cin >> a >> b >> c >> N;
	for(int i=0;i<N;i++)
		cin >> x[i];
	int ans = 0;
	for(int i=0;i<N;i++)
		if(x[i] > b && x[i] < c)
			ans++;
	cout << ans << '\n';
}