#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int * a=new int[9+1];
string zrob(int idx)
{

    string res="";
    for(int i=0;i<idx;i++) res+=s[i];
    bool ok =true;
    for(int i=idx;i<n;i++)
    {
        if(ok==false) res+=s[i];
        else
        {
            int ile=a[s[i]-'0'];
            int ileakt=s[i]-'0';
            if(ile<ileakt)
            {
                ok = false;
                res+=s[i];
            }
            else
            {
                res+=char(48+a[s[i]-'0']);
            }
        }
    }
    return res;
}

int main()
{
    cin>>n>>s;
    for(int i=1;i<=9;i++) cin>>a[i];
    for(int i=0;i<n;i++)
    {
        int val=s[i]-'0';
        int ilemozna=a[val];
        if(ilemozna>val)
        {
            cout<<zrob(i);
            return 0;
        }
    }
    cout<<s;
    return 0;
}