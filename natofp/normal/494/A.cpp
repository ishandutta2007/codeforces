#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    string s; cin>>s;
    int a=0;
    vector<int> ans;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(') a++;
        else if(s[i]==')') a--;
        else
        {
            if(a<=0) {cout<<-1; return 0;}
            a--; ans.push_back(1);
        }
        if(a<0) {cout<<-1; return 0;}
    }
    
    int i=s.length()-1;
    int ile=0;
    while(s[i]!='#')
    {
        if(s[i]=='(') ile++;
        else ile--;
        if(ile>0) {cout<<-1; return 0;}
        i--;
    }
    ans[ans.size()-1]+=a;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}