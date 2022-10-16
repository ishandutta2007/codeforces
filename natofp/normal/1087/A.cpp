#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin>>s;
    int n=s.length();
    string t="";
    if(n%2==0)
    {
        for(int i=0;i<n/2;i++)
        {
            t+=s[n-1-i];
            t+=s[i];
        }
    }
    else
    {
        for(int i=0;i<n/2;i++)
        {

            t+=s[i];
            t+=s[n-1-i];

        }
        t+=s[n/2];
    }
    reverse(t.begin(),t.end());
    cout<<t;
    return 0;
}