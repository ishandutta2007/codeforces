#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string str,ans="";
        cin>>str;
        char last=str[0];
        int act=1,lastact;
        vector <int> ile;
        for(int i=1;i<n;i++)
        {
            if(str[i]==last)
            {
                act++;
            }
            else
            {
                ile.push_back(act);
                act=1;
                last=str[i];
            }
        }
        ile.push_back(act);
        char q=str[0];
        for(int i=0;i<ile.size();i++)
        {
            if(q=='1'&&i+1<ile.size())
            {
                ile[i]=0;
            }
            if(q=='0'&&i+2<ile.size()&&i>0) ile[i]=0;
            else if(q=='0'&&i>0) ile[i]=1;
            if(q=='1') q='0';
            else q='1';
        }
        q=str[0];
        for(int i=0;i<ile.size();i++)
        {
            for(int j=0;j<ile[i];j++)
            {
                cout<<q;
            }
            if(q=='1') q='0';
            else q='1';
        }
        cout<<endl;
    }
    return 0;
}