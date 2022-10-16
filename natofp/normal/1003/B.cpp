#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,x;
    cin>>a>>b>>x;
    string wynik="";
    bool xd=true;
    if(b>a) xd=false;
    int l=-1;
    while(x>=1)
    {
        x--;
        if(xd) {wynik+='0'; a--;}
        else {wynik+='1'; b--;}
        xd=!xd;
        l++;
    }
    if(wynik[l]=='0')
    {
        for(int i=0;i<a;i++) wynik+='0';
        for(int i=0;i<b;i++) wynik+='1';
    }
    else
    {
        for(int i=0;i<b;i++) wynik+='1';
        for(int i=0;i<a;i++) wynik+='0';
    }
    cout<<wynik;



    return 0;
}