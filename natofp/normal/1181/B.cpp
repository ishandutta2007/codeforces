#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string add(string a,string b)
{
    string res;
    int n=max((int)a.size(),(int)b.size());
    if(a.size()>b.size()) swap(a,b);
    int roz=(int)b.size()-(int)a.size();
    string nowy;
    for(int i=0;i<roz;i++) nowy+='0';
    nowy+=a;
    a=nowy;
    int p=0;
    for(int i=n-1;i>=0;i--)
    {
        int xd1,xd2;
        if(i>=a.size()) xd1=0;
        else xd1=a[i]-'0';
        if(i>=b.size()) xd2=0;
        else xd2=b[i]-'0';
        int suma=xd1+xd2+p;
        p=0;
        if(suma>=10)
        {
            suma-=10;
            p++;
        }
        res+=('0'+suma);
    }
    reverse(res.begin(),res.end());
    return res;
}

bool por(string a,string b)
{
    if(a.length()>b.length()) return true;
    if(a.length()<b.length()) return false;
    int n=a.length();
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i]) continue;
        if(a[i]>b[i]) return true;
        if(a[i]<b[i]) return false;
    }
    return true;
}

void obrob(string s)
{
    int n=s.length();
    int idx=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]!='0')
        {
            idx=i;
            break;
        }
    }
    for(int i=idx;i<n;i++) cout<<s[i];
}

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    string res=s+"9";
    int ile=0;
    if(s[0]=='0')
    {
        string a,b;
        a="0";
        for(int i=1;i<n;i++) b+=s[i];
        obrob(add(a,b));
        return 0;
    }
    for(int i=n/2;i<n;i++)
    {
        if(s[i]!='0')
        {
            ile++;
            if(ile>=3) break;
            string a,b;
            for(int j=0;j<i;j++) a+=s[j];
            for(int j=i;j<n;j++) b+=s[j];
            string wyn=add(a,b);
            if(por(res,wyn)) res=wyn;
        }
    }
    ile=0;
    for(int i=n/2-1;i>=1;i--)
    {
        if(s[i]!='0')
        {
            ile++;
            if(ile>=3) break;
            string a,b;
            for(int j=0;j<i;j++) a+=s[j];
            for(int j=i;j<n;j++) b+=s[j];
            string wyn=add(a,b);
            if(por(res,wyn)) res=wyn;
        }
    }
    obrob(res);
    return 0;
}