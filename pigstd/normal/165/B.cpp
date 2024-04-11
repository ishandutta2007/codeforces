#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k,ans;

bool check(int s)
{
	int c=k,sum=s;
	while(1)
	{
		sum+=s/c,c*=k;
		if (s/c==0)break;
	}return sum>=n;
}

signed main()
{
	cin>>n>>k;
	int tl=1,tr=n;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (check(Mid))
			ans=Mid,tr=Mid-1;
		else
			tl=Mid+1;	
	}cout<<ans;
}