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
        int idx=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='8')
            {
                idx=i;
                break;
            }
        }
        if(idx==-1 || n-1-idx<10) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}