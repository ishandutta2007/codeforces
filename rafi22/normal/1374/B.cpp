#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        long long n,pot2=0,pot3=0,n1;
        cin>>n;
        n1=n;
        while(n1%2==0)
        {
            pot2++;
            n1/=2;
        }
        while(n1%3==0)
        {
            pot3++;
            n1/=3;
        }
        if(pow(2,pot2)*pow(3,pot3)!=n||pot2>pot3) cout<<-1<<endl;
        else cout<<pot3+pot3-pot2<<endl;

    }
    return 0;
}