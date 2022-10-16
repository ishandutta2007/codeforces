#include <iostream>
#include <bits/stdc++.h>


using namespace std;



int main()
{
    int n; cin>>n;
    string s; cin>>s;
    int j=-1;
    bool xd=false;
    for(int i=1;i<n;i++)
    {
        if(s[i]<s[i-1]) {j=i-1; break;}
        if(s[i]!=s[i-1]) xd=true;
    }
    if(j!=-1)
    {
        for(int i=0;i<n;i++)
        {
            if(i!=j) cout<<s[i];
        }
    }
    else if(xd==false)
    {
        for(int i=0;i<n-1;i++) cout<<s[0];
    }
    else
    {
        for(int i=0;i<n-1;i++) cout<<s[i];
    }

    return 0;
}