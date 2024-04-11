#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q; cin>>q;
    while(q--)
    {
        int n; cin>>n;
        string s; cin>>s;
        if(s.length()==2)
        {
            if(s[1]<=s[0]) cout<<"NO"<<endl;
            else cout<<"YES"<<endl<<"2"<<endl<<s[0]<<" "<<s[1]<<endl;
        }
        else
        {
            cout<<"YES"<<endl<<"2"<<endl;
            cout<<s[0]<<" ";
            for(int i=1;i<s.length();i++) cout<<s[i];
            cout<<endl;
        }
    }
    return 0;
}