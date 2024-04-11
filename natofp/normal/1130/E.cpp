#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int k; cin>>k;
    int n=2000;
    cout<<n<<endl;
    cout<<-1<<" ";
    int sum=k+2000;
    for(int i=1;i<n;i++)
    {
        if(sum>0)
        {
            if(sum<=1000000)
            {
                cout<<sum<<" ";
                sum=0;
            }
            else
            {
                cout<<1000000<<" ";
                sum-=(1e6);
            }
        }
        else cout<<0<<" ";
    }
    return 0;
}