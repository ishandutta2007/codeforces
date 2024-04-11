#include <iostream>
using namespace std;

int main()
{
	int N,D,H;
	cin >> N >> D >> H;
	if(D > 2*H)
	{
		cout << -1 << '\n';
		return 0;
	}
	if(D==H && H==1 && N>2)
	{
		cout << -1 << '\n';
		return 0;
	}
	if(D==H && H<N-1)
	{
		for(int i=1;i<=H;i++)
			cout << i << ' ' << i+1 << '\n';		
		for(int i=H+2;i<=N;i++)
			cout << 2 << ' ' << i << '\n';
		return 0;
	}
	for(int i=1;i<=H;i++)
		cout << i << ' ' << i+1 << '\n';
	for(int i=H+2;i<=D+1;i++)
	{
		if(i==H+2) cout << 1 << ' ' << i << '\n';
		else cout << i-1 << ' ' << i << '\n';
	}
	for(int i=D+2;i<=N;i++)
		cout << 1 << ' ' << i << '\n';
}