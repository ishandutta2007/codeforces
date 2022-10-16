#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; string s;
    cin>>n>>s;
    string ans="";
    int pos=0;
    for(int i=1;i*(i-1)/2<n;i++)
    {
        ans+=s[pos];
        for(int j=0;j<i;j++)
        {
            pos++;
        }
    }
    cout<<ans<<endl;
    return 0;
}