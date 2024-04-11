#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        long long n;
        cin>>n;
        long long act=3;
        for(int i=2;i<70;i++)
        {
            if(n%act==0)
            {
                cout<<n/act<<endl;
                break;
            }
            act+=pow(2,i);
        }
    }
    return 0;
}