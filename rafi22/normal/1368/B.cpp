#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,ile=1;
    long long tab[10];
    for(long long i=0;i<10;i++) tab[i]=1;
    cin>>n;
    while(ile<n)
    {
        for(long long i=0;i<10;i++)
        {
            if(ile>=n) break;
            ile/=tab[i];
            tab[i]++;
            ile*=tab[i];
        }
    }
    string str="codeforces";
    for(long long i=0;i<10;i++)
    {
        for(long long j=0;j<tab[i];j++)
        {
            cout<<str[i];
        }
    }
    return 0;
}