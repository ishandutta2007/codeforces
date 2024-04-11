#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    int ile=0;
    for(int i=0;i<n;i+=2)
    {
        if(s[i]==s[i+1])
        {
            ile++;
            if(s[i]=='b') s[i]='a';
            else s[i]='b';
        }
    }
    cout<<ile<<endl;
    cout<<s;
    return 0;
}