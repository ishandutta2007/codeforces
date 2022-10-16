#include <iostream>
#include <bits/stdc++.h>
#define ll long long int

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin>>s;
    cout<<"Mike"<<"\n";
    char xd=s[0];
    for(int i=1;i<s.length();i++)
    {
        if(xd<s[i]) cout<<"Ann"<<"\n";
        else cout<<"Mike"<<"\n";
        xd=min(xd,s[i]);
    }
    return 0;
}