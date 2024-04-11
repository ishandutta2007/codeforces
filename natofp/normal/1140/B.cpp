#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        string s; cin>>s;
        int p=1111;
        int l=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='>')
            {
                p=i; break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='<')
            {
                l=i; break;
            }
        }

            cout<<min(p,n-1-l)<<endl;

    }
    return 0;
}