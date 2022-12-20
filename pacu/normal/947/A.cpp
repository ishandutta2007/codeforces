#include <iostream>
#include <algorithm>
using namespace std;

int mxp[1000001];

int main()
{
	int x;
	cin >> x;
	mxp[2] = 2;
	for(int i=2;i<=1000000;i++)
	{
		if(mxp[i]==0)
			mxp[i] = i;
		for(int j=i;j<=1000000;j+=i)
			mxp[j] = max(mxp[j], mxp[i]);
	}
	int p = mxp[x];
	int ans = x;
	for(int i=x-p+1;i<=x;i++)
		if(i != mxp[i])
			ans = min(ans,i-mxp[i]+1);
	cout << ans << '\n';
}