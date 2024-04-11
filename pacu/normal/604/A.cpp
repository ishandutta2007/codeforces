#include <iostream>
using namespace std;

int m[5];
int w[5];
int hs,hu;

int main()
{
	for(int i=0;i<5;i++) cin >> m[i];
	for(int i=0;i<5;i++) cin >> w[i];
	cin >> hs >> hu;
	int ans = 100*hs-50*hu;
	for(int i=0;i<5;i++)
		ans += max(3*50*(i+1),(500-2*m[i])*(i+1)-50*w[i]);
	cout << ans << '\n';
}