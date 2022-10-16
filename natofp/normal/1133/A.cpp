#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h1,m1,h2,m2;
    string a,b; cin>>a>>b;
     h1=(a[0]-'0')*10+a[1]-'0';
     m1=(a[3]-'0')*10+a[4]-'0';
     h2=(b[0]-'0')*10+b[1]-'0';
     m2=(b[3]-'0')*10+b[4]-'0';
    int ile=(h1+h2)*60;
    ile+=m1;
    ile+=m2;
    int godziny=ile/120;
    if(godziny<=9) cout<<"0";
    cout<<godziny<<":";
    int minuty=ile-godziny*120;
    minuty/=2;
    if(minuty<=9) cout<<"0";
    cout<<minuty;

    return 0;
}