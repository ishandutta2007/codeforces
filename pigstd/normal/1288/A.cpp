#include<bits/stdc++.h>
#define int long long
using namespace std;

int T,n,s;

signed main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>s;
        if((n-n/2)*(n/2+1)>=s)
        	cout<<"YES"<<endl;
        else
        	cout<<"NO"<<endl;
    }
    return 0;
}