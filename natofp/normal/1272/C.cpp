#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=2e5+5;
int a[nax];

int n,k;
bool ok[26];

int main()
{
    cin>>n>>k;
    string s; cin>>s;
    for(int i=1;i<=k;i++)
    {
        char x; cin>>x;
        ok[x-'a']=true;
    }
    ll res=0;
    ll akt=0;
    for(int i=0;i<n;i++)
    {
        if(ok[s[i]-'a']==true) akt++;
        else
        {
            res+=((akt)*(akt+1)/2);
            akt=0;
        }
    }
    res+=((akt)*(akt+1)/2);
    cout<<res;
    return 0;
}