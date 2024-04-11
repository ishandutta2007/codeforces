#include <bits/stdc++.h>
#define ll long long int
using namespace std;


bool por(vector<char> a,vector<char>b)
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i]) return false;
    }
    return true;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        vector<char> a;
        vector<char> h;
        string s; cin>>s;
        for(int i=0;i<s.length();i++)
        {
            a.push_back(s[i]);
        }
        sort(a.begin(),a.end());
        cin>>s;
        for(int i=0;i<s.length();i++)
        {
            h.push_back(s[i]);
        }
        if(h.size()<a.size())
        {
            cout<<"NO"<<endl;
            continue;
        }
        bool ok = false;
        for(int i=0;i+a.size()-1<h.size();i++)
        {
            vector<char> xd;
            for(int j=i;j<i+a.size();j++)
            {
                xd.push_back(h[j]);
            }
            sort(xd.begin(),xd.end());
            if(por(xd,a))
            {
                cout<<"YES"<<endl;
                ok = true;
                break;
            }
        }
        if(ok) continue;
        cout<<"NO"<<endl;

    }


    return 0;
}