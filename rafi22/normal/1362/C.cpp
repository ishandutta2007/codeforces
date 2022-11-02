#include <bits/stdc++.h>

using namespace std;

long long DP[100];

string Tobin(long long n)
{
    string wyn="",wyn1="";
    while(n>0)
    {
        wyn+=(char)(n%2+48);
        n/=2;
    }
    /*for(int i=pot-1;i>=0;i--)
    {
        wyn1+=wyn[i];
    }*/
    return wyn;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        long long n,res=0;
        cin>>n;
        string str=Tobin(n);
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='1') res+=pow(2,i+1)-1;
        }
        cout<<res<<endl;
    }
    return 0;
}