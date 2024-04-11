#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int check(string s,int n)
{
    for(int i=0;i<n;i++)
    {
        if(s[i]==s[s.length()-n+i]) continue;
        else {return false;}
    }
    return true;
}

int getmax(string s)
{
    int i=1;
    int d=0;
    while(i<s.length())
    {
        if(check(s,i)) d=i;
        i++;
    }
    return d;
}

string przytnij(string s,int n)
{
    string odp="";
    for(int i=n;i<s.length();i++)
    {
        odp+=s[i];
    }
    return odp;
}


int main()
{
    int n,k;
    cin>>n>>k;
    string t;
    cin>>t;
    string odp="";
    odp+=t;
    int j=getmax(t);
    for(int i=1;i<k;i++)
    {
        odp+=przytnij(t,j);
    }
    cout<<odp;

    return 0;
}