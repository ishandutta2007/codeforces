#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        long long x,y,a,b;
        cin>>x>>y>>a>>b;
        cout<<(max(x,y)-min(x,y))*a+min(x,y)*b<<endl;
    }*/
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string str;
        cin>>str;
        bool is1=0,is2=0;
        for(int j=0;j<str.size();j++)
        {
            if(str[j]=='1') is1=1;
            else is2=1;
        }
        if(is1&&is2)
        {
            for(int j=0;j<str.size();j++) cout<<"01";
        }
        else if(is1)
        {
            for(int j=0;j<str.size();j++) cout<<"1";
        }
        else
        {
            for(int j=0;j<str.size();j++) cout<<"0";
        }
        cout<<endl;
    }
    return 0;
}