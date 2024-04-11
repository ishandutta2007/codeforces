#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,n,m,i,j;
ll working[127];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;

    string s; char c;
    for (i=1;i<=n;i++)
    {
        cin>>s;
        m=s.length();
        for (j=0;j<128;j++) working[j]=0;
        a=1;
        for (j=1;j<m;j++)  if (s[j]!=s[j-1]) { if (a%2) working[s[j-1]]=1; a=1;} else a++;
        if (a % 2)
            working[s[j - 1]] = 1;
        a = 1;
        a = 1;
        for (j=97;j<=122;j++) if (working[j]==1) {c=j; cout<<c;}
        cout<<endl;
    }
}