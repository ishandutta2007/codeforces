#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
    int n; cin>>n;
    vector<int> a(10,0);
    for(int i=1;i<=9;i++) cin>>a[i];
    int idx=-1; int naj=1e9;
    for(int i=1;i<=9;i++)
    {
        if(a[i]<=naj)
        {
            naj=a[i];
            idx=i;
        }
    }
    if(n<naj) {cout<<-1; return 0;}
    int ile=n/naj;
    int res=n%naj;
    for(int i=1;i<=9;i++)
    {
        a[i]-=naj;
    }
    string ans="";
    while(ans.length()<ile && res)
    {
        int t=ans.length();
        for(int i=9;i>=1;i--)
        {
            if(a[i]<=res)
            {
                ans+=char('0'+i);
                res-=a[i];
                break;
            }
        }
        if(ans.length()==t) break;

    }
    for(int i=ans.length();i<ile;i++)
    {
        ans+=char('0'+idx);
    }
    cout<<ans;
    return 0;
}