#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b=1,n,m,i,j,k,t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    string s;
    for (k=1;k<=t;k++) {
        cin>>n;
        b=1; a=0;
        for (i=1;i<=n;i++) {cin>>s; m=s.length(); if (m%2) b=0; for (j=0;j<m;j++) if (s[j]=='1') a++;}
        if ((b)and(a%2)) cout<<n-1; else cout<<n;
        cout<<endl;
    }
}