#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin>>s;
    string ans="";
    int wsk1=0;
    int wsk2=s.length()-1;
    while(wsk1+3<=wsk2)
    {
        if(s[wsk1]==s[wsk2])
        {
            ans+=s[wsk1];
            wsk1++; wsk2--;
        }
        else if(s[wsk1+1]==s[wsk2])
        {
            ans+=s[wsk1+1];
            wsk1+=2;
            wsk2--;
        }
        else if(s[wsk1]==s[wsk2-1])
        {
            ans+=s[wsk1];
            wsk1++;
            wsk2-=2;
        }
        else if(s[wsk1+1]==s[wsk2-1])
        {
            ans+=s[wsk1+1];
            wsk1+=2;
            wsk2-=2;
        }
    }
    if(wsk1<=wsk2) ans+=s[wsk1];
    cout<<ans;
    for(int i=ans.size()-2;i>=0;i--) cout<<ans[i];
    return 0;
}