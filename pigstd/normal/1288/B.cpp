#include<bits/stdc++.h>
#define int long long
using namespace std;

int T,a,b;

signed main()
{
    cin>>T;
    while(T--)
    {
    	cin>>a>>b;
    	int sum=0,e=9;
    	while(e<=b)
    		e=e*10+9,sum++;
    	cout<<sum*a<<endl;
    }
    return 0;
}