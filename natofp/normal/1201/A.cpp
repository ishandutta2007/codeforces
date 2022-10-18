#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    long long int res=0;
    vector<string> s;
    for(int i=0;i<n;i++)
    {
        string x; cin>>x;
        s.push_back(x);
    }
    int * a=new int[m+1];
    for(int i=0;i<m;i++) cin>>a[i];
    for(int i=0;i<m;i++)
    {
        int xx,b,c,d,e;
       xx=b=c=d=e=0;
        for(int j=0;j<n;j++)
        {
            if(s[j][i]=='A') xx++;
            if(s[j][i]=='B') b++;
            if(s[j][i]=='C') c++;
            if(s[j][i]=='D') d++;
            if(s[j][i]=='E') e++;
        }
        xx=max(xx,b);
        xx=max(xx,c);
        xx=max(xx,d);
        xx=max(xx,e);
        res+=(long long int)xx*a[i];
    }
    cout<<res;
    return 0;
}