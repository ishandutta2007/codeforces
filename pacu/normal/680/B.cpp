#include <iostream>
using namespace std;

int t[100];
int a,N;

int main()
{
	cin >> N >> a;
	a--;
	for(int i=0;i<N;i++) cin >> t[i];
	int ans = t[a];
	for(int d=1;d<N;d++)
	{
		if(a-d < 0 && a+d >= N) continue;
		if(a-d < 0) ans += t[a+d];
		else if(a+d >= N) ans += t[a-d];
		else if(t[a+d] && t[a-d]) ans += 2;
	}
	cout << ans << '\n';
}