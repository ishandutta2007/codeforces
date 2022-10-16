#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int INF=1e9;
const int modulo=1e9+7;
long long int pom(long long int a,long long int b,int mod=modulo)
{
    a%=modulo;
    b%=modulo;
    return (a*1ll*b)%mod;
}

int main()
{
   int sell=INF;
    int buy=-INF;
    int ans=1;
    set<int> a;
    int tot=0;
    int n;
    cin>>n;
    set<int>::iterator it;
    while(n--)
    {
        string s; int p;
        cin>>s>>p;
        if(s=="ADD")
        {
            a.insert(p);
            if(p>buy && p<sell) tot++;
        }
        else
        {
            tot=0;
            if(p<buy || p>sell) {ans=0;}
            if(p>buy && p<sell) {ans=pom(ans,2);}
            it=a.upper_bound(p);
            if(it==a.end()) sell=INF;
            else sell=*it;
            it=a.lower_bound(p);
            if(it==a.begin()) buy=-INF;
            else buy=*(--it);
            a.erase(p);

        }
    }
    ans=pom(ans,tot+1);
    cout<<ans;

    return 0;
}