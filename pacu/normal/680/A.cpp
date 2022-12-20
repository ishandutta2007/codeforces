#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[5];
	for(int i=0;i<5;i++) cin >> a[i];
	sort(a,a+5);
	int ans = a[0]+a[1]+a[2]+a[3]+a[4];
	if(a[2]==a[4]) ans = min(ans,a[0]+a[1]);
	if(a[1]==a[3]) ans = min(ans,a[0]+a[4]);
	if(a[0]==a[2]) ans = min(ans,a[3]+a[4]);
	if(a[3]==a[4]) ans = min(ans,a[0]+a[1]+a[2]);
	if(a[2]==a[3]) ans = min(ans,a[0]+a[1]+a[4]);
	if(a[1]==a[2]) ans = min(ans,a[0]+a[3]+a[4]);
	if(a[0]==a[1]) ans = min(ans,a[2]+a[3]+a[4]);
	cout << ans << '\n';
}