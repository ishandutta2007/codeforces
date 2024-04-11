#include <iostream>
#include <bits/stdc++.h>

using namespace std;
map<long long int,long long int> lp;
set<long long int> lista;
map<long long int,long long int> ile;
long long int ans=1e18;
void zrob(long long int b)
{
    for(long long int i=2;i*i<=b;i++)
    {
        while(b%i==0)
        {
            lp[i]++;
            b/=i;
            lista.insert(i);
        }
    }
    if(b!=1)
    {
        lp[b]++;
        lista.insert(b);
    }
}

void policz(long long int n,long long int p)
{
    long long int pom=p;
    long long int res=0;
    while(p<=n)
    {
        res+=(n/p);
        if((n/pom)+1<p) break;
        else p*=pom;
    }
    ans=min(ans,res/lp[pom]);
}

int main()
{
    long long int n,b;
    cin>>n>>b;
    zrob(b);
    set<long long int>::iterator it;
    it=lista.begin();
    while(it!=lista.end())
    {
        long long int p=*it;
        policz(n,p);
        it++;
    }
    cout<<ans;
    return 0;
}