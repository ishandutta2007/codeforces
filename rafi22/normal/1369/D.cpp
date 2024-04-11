#include <bits/stdc++.h>

using namespace std;

long long DP[20000007];
long long mod=1000000007;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    long long zero=1,one=1,temp;
    DP[2]=1;
    DP[1]=1;
    for(int i=3;i<=20000000;i++)
    {
        temp=one*2+zero;
        temp%=mod;
        one=zero;
        zero=temp;
        DP[i]=zero+DP[i-3];
        DP[i]%=mod;
    }
    while(t--)
    {
        long long n;
        cin>>n;
        cout<<(4*DP[max((long long)0,n-2)])%mod<<endl;

    }



    return 0;
}