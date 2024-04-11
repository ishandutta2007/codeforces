#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=105;
ll a[nax];
vector<ll> s;
int n,m;

int solve(int k,int pos)
{
    int val=s[n-k];
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>val) cnt++;
    }
    int ile=k-cnt;
    int p=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<val) continue;
        if(a[i]==val && ile==0) continue;
        if(p==pos) return a[i];
        if(a[i]==val) ile--;
        p++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s.push_back(a[i]);
    }
    sort(s.begin(),s.end());
    cin>>m;
    while(m--)
    {
        int x,y; cin>>x>>y;
        cout<<solve(x,y)<<endl;
    }
    return 0;
}