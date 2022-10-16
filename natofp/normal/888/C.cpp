#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s; cin>>s;
    vector<int> res;
    int ans=1e9;
    for(int i=0;i<26;i++)
    {
        char x='a'+i;
        int last=-1;
        int akt=0;
        for(int j=0;j<s.length();j++)
        {
            if(s[j]==x)
            {
                akt=max(akt,j-last);
                last=j;
            }
        }
        int n=s.length();
        akt=max(akt,n-last);
        res.push_back(akt);
        ans=min(ans,akt);
    }
    cout<<ans;
    return 0;
}