#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void Wypisz(string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='.') cout<<s[i];
        else cout<<'0';
    }
}

int main()
{
    int n,p;
    cin>>n>>p;
    string s;

    cin>>s;
    for(int i=0;i<p;i++)
    {

        int a=0;
        int b=0;
        int suma=0;
        for(int j=i;j<n;j+=p)
        {

            if(s[j]=='0') a++;
            else if(s[j]=='1') b++;
            suma++;
        }

        for(int j=i;j<n;j+=p)
        {
            if(a>0 && b>0) {Wypisz(s); return 0;}
            if(s[j]=='.')
            {
                if(a>0) {s[j]='1'; Wypisz(s); return 0;}
                else if(b>0) {s[j]='0'; Wypisz(s); return 0;}
                else if(suma>0) {s[j]='0'; a++;}
            }
        }

    }
    cout<<"NO";
    return 0;
}