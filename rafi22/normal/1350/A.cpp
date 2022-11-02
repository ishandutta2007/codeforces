#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,k,d;
        cin>>n>>k;
        for(int i=2;i<=n;i++)
        {
            if(n%i==0)
            {
                d=i;
                break;
            }
        }
        cout<<n+d+2*(k-1)<<endl;
    }
    return 0;
}