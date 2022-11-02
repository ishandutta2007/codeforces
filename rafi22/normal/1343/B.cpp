#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        if(n/2%2==0)
        {
            cout<<"YES"<<endl;
            int act=2;
            for(int j=0;j<n/2;j++)
            {
                cout<<act<<" ";
                act+=2;
            }
            act=1;
            for(int j=0;j<n/2-1;j++)
            {
                cout<<act<<" ";
                act+=2;
            }
            cout<<act+n/2<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}