#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,d;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>a>>b>>c>>d>>n;
	int minn=max(n-a*(c-1)-b*(d-1),0);
	int maxx=0;
	if(c>d)swap(c,d),swap(a,b);
	while(a&&n>=c)
	{
		n-=c;
		maxx++;
		a--;
	}
	while(b&&n>=d)
	{
		n-=d;
		maxx++;
		b--;
	}
	cout<<minn<<' '<<maxx<<endl;
	return 0;
}