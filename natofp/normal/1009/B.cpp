#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int a=0;
    int i=0;
    while(i<n && s[i]!='2')
    {
        if(s[i]=='0') a++;
        i++;

    }
    int x=i;
    int b=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1') b++;
    }
    string w="";
    for(int i=0;i<a;i++) w+='0';
    for(int i=0;i<b;i++) w+='1';
    for(int i=x;i<n;i++)
    {
        if(s[i]=='0') w+='0';
        else if(s[i]=='2') w+='2';
    }
    cout<<w;




    return 0;
}