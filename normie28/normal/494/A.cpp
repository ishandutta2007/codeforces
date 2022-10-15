#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
 
string s;
vector<int> ans;
int main()
{
    cin>>s;
    int sum = 0;
    int flag = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')sum--;
        else if(s[i]==')')sum++;
        else
        {ans.push_back(i);flag++;}
        if(sum+flag>0)return puts("-1");
    }
    int k = ans.size();
    if(k+sum>0)return puts("-1");
    else if(k==0&&sum!=0)return puts("-1");
    else
    {
        int Ans = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')Ans--;
            else if(s[i]==')')Ans++;
            else if(i==ans[ans.size()-1])Ans+=0-(sum+k-1);
            else Ans++;
            if(Ans>0)return puts("-1");
        }
        for(int i=0;i<k;i++)
        {
            if(i==k-1)
                cout<<0-(sum+k-1)<<endl;
            else
                cout<<1<<endl;
        }
    }
}