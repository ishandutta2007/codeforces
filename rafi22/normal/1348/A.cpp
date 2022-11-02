#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        long long a1=0,a2=0;
        cin>>n;
        a1+=pow(2,n);
        for(int i=1;i<n/2;i++)
        {
            a1+=pow(2,i);
        }
        for(int i=n/2;i<n;i++)
        {
            a2+=pow(2,i);
        }
        cout<<a1-a2<<endl;
    }
    return 0;
}