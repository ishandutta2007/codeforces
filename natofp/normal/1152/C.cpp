#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> daj(int n)
{
    vector<int> res;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(i*i==n)
            {
                res.push_back(i);
            }
            else
            {
                res.push_back(i);
                res.push_back(n/i);
            }
        }
    }
    return res;
}
long long int wyn=0;


int main()
{
    long long int res=1e18+5;
    long long int a,b; cin>>a>>b;
    if(a<b) swap(a,b);
    long long int d=(a-b);
    vector<int> dziel=daj(d);
    for(int i=0;i<dziel.size();i++)
    {
        long long int t=dziel[i];
        long long int ile=a%t;
        long long int k=(t-ile)%t;
        long long int pos=(a+k)*(b+k)/t;
        if(pos<res)
        {
            res=pos;
            wyn=k;
        }
    }
    cout<<wyn;
    return 0;
}