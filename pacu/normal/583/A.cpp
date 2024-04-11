#include <iostream>
using namespace std;

int v[51],h[51];
int N;

int main()
{
	int N;
	cin >> N;
	int a,b;
	for(int i=1;i<=N*N;i++)
	{
		cin >> a >> b;
		if(!h[a] && !v[b])
		{
			cout << i << '\n';
			h[a] = v[b] = 1;
		}
	}
}