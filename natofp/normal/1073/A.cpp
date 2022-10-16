#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    bool xd=false;
    for(int i=1;i<n;i++)
    {
        if(s[i]!=s[i-1])
        {
            cout<<"YES"<<endl; cout<<s[i-1]<<s[i]; return 0;
        }
    }
    cout<<"NO";
    return 0;
}