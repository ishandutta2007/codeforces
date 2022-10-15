#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,n,m,i,j,k,bl[300001],res;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>s;
    j=0; k=1;
    for (i=1;i<s.length();i++) if (s[i]!=s[i-1])
    {
        j++;
        bl[j]=k;
        k=1;
    }
    
    else k++;
    j++;
    bl[j] = k;
    k = 1;
    res=0;
    for (i=1;i<=j;i++) res+=bl[i];
    res*=2;
    res-=(bl[1]+bl[j]);
    res-=j-1;
    cout<<(n*(n-1)/2)-res;
}