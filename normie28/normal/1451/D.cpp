#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,d,t,u,v,c0,c2;
long long dp[101][101];
int main()
{
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>c0;
	for (c2=0;c2<c0;c2++)
	{
	cin>>k>>d;
	u=(k*k)/(d*d);
	t=0;
	while(t*t*2<=u)
	{
		t++;
	}
	v=u-(2*(t-1)*(t-1));
//	cout<<u<<' '<<v<<' '<<t<<endl;
	if (v<t*t-(t-1)*(t-1)) cout<<"Utkarsh\n";
	else cout<<"Ashish\n";
}
}