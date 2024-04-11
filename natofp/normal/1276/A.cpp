#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
bool xd[222222];
string s;
vector<int> ans;
int a=0;
int b=0;
int c=0;
void policz(int idx)
{
    if(s[idx]=='t' && s[idx+1]=='w' && s[idx+2]=='o') b++;
    if(s[idx]=='o' && s[idx+1]=='n' && s[idx+2]=='e') a++;
}
 
void okk(int idx)
{
    if(s[idx-2]=='t' && s[idx-1]=='w' && s[idx]=='o' && s[idx+1]=='n' && s[idx+2]=='e')
    {
        c++; ans.push_back(idx);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        ans.clear();
        cin>>s;
        a=0; b=0; c=0;
        int n=s.length();
        for(int i=0;i<=n;i++) xd[i]=false;
        for(int i=0;i<n-2;i++)
        {
            policz(i);
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='o' && i>=2 && i<n-2) okk(i);
        }
        for(int i=0;i<ans.size();i++) xd[ans[i]]=true;
        for(int i=1;i<n-1;i++)
        {
            if(s[i]=='n')
            {
                if(s[i-1]=='o' && s[i+1]=='e' && xd[i-1]==false && xd[i]==false && xd[i+1]==false)
                {
                    ans.push_back(i); xd[i]=true;
                }
            }
            if(s[i]=='w')
            {
                if(s[i-1]=='t' && s[i+1]=='o' && xd[i-1]==false && xd[i]==false && xd[i+1]==false)
                {
                    ans.push_back(i); xd[i]=true;
                }
            }
        }
        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size();i++) cout<<ans[i]+1<<" ";
        cout<<"\n";
 
    }
    return 0;
}