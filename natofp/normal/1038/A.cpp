#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin>>n;
    int k; cin>>k;
    string s; cin>>s;
    vector<int> a(26,0);
    for(int i=0;i<s.length();i++)
    {
        a[s[i]-65]++;
    }
    int ans=1e6;
    for(int i=0;i<k;i++) ans=min(ans,a[i]);
    cout<<ans*k;

    return 0;
}