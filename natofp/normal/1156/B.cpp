#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool proba(int a,int b,int c)
{
    if(abs(a-b)==1) return false;
    if(abs(b-c)==1) return false;
    return true;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        int a[26];
        memset(a,0,sizeof a);
        for(int i=0;i<s.length();i++)
        {
            a[s[i]-'a']++;
        }
        vector<int> xd;
        for(int i=0;i<26;i++)
        {
            if(a[i]>0) xd.push_back(i);
        }
        vector<int> wynik;
        if(xd.size()>=4)
        {
            for(int i=1;i<xd.size();i+=2) wynik.push_back(xd[i]);
        for(int i=0;i<xd.size();i+=2) wynik.push_back(xd[i]);
        bool ok = true;
        for(int i=1;i<wynik.size();i++)
        {
            if(abs(wynik[i]-wynik[i-1])==1) {cout<<"No answer"<<endl; ok=false; break;}
        }
        if(ok==false) continue;
        for(int i=0;i<wynik.size();i++)
        {
            for(int j=0;j<a[wynik[i]];j++)
            {
                cout<<char('a'+wynik[i]);
            }
        }
        cout<<endl;
        }
        else if(xd.size()<=3)
        {
            if(xd.size()==1)
            {
                int val=xd[0];
                for(int i=0;i<a[val];i++) cout<<char('a'+val);
                cout<<endl;
                continue;
            }
            else if(xd.size()==2)
            {
                int val1,val2;
                val1=xd[0];
                val2=xd[1];
                if(abs(val1-val2)==1) {cout<<"No answer"<<endl; continue;}
                for(int i=0;i<a[val1];i++) cout<<char('a'+val1);
                for(int i=0;i<a[val2];i++) cout<<char('a'+val2);
                cout<<endl;
                continue;
            }
            else if(xd.size()==3)
            {
                int val1,val2,val3;
                val1=xd[0];
                val2=xd[1];
                val3=xd[2];
                if(proba(val1,val2,val3))
                {
                    for(int i=0;i<a[val1];i++) cout<<char('a'+val1);
                    for(int i=0;i<a[val2];i++) cout<<char('a'+val2);
                    for(int i=0;i<a[val3];i++) cout<<char('a'+val3);
                    cout<<endl;
                    continue;
                }
                else if(proba(val1,val3,val2))
                {
                    for(int i=0;i<a[val1];i++) cout<<char('a'+val1);
                    for(int i=0;i<a[val3];i++) cout<<char('a'+val3);
                    for(int i=0;i<a[val2];i++) cout<<char('a'+val2);
                    cout<<endl;
                    continue;
                }
                else if(proba(val2,val1,val3))
                {
                    for(int i=0;i<a[val2];i++) cout<<char('a'+val2);
                    for(int i=0;i<a[val1];i++) cout<<char('a'+val1);
                    for(int i=0;i<a[val3];i++) cout<<char('a'+val3);
                    cout<<endl;
                    continue;
                }
                else if(proba(val2,val3,val1))
                {
                    for(int i=0;i<a[val2];i++) cout<<char('a'+val2);
                    for(int i=0;i<a[val3];i++) cout<<char('a'+val3);
                    for(int i=0;i<a[val1];i++) cout<<char('a'+val1);
                    cout<<endl;
                    continue;
                }
                else if(proba(val3,val1,val2))
                {
                    for(int i=0;i<a[val3];i++) cout<<char('a'+val3);
                    for(int i=0;i<a[val1];i++) cout<<char('a'+val1);
                    for(int i=0;i<a[val2];i++) cout<<char('a'+val2);
                    cout<<endl;
                    continue;
                }
                else if(proba(val3,val2,val1))
                {
                    for(int i=0;i<a[val3];i++) cout<<char('a'+val3);
                    for(int i=0;i<a[val2];i++) cout<<char('a'+val2);
                    for(int i=0;i<a[val1];i++) cout<<char('a'+val1);
                    cout<<endl;
                    continue;
                }
                else cout<<"No answer"<<endl;
                continue;
            }
        }
    }
    return 0;
}