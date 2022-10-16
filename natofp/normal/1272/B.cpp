#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;



int main()
{
    int q; cin>>q;
    while(q--)
    {
        string s; cin>>s;
        int a=0;
        int b=0;
        int c=0;
        int d=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='L') a++;
            if(s[i]=='R') b++;
            if(s[i]=='U') c++;
            if(s[i]=='D') d++;
        }
        int k=min(a,b);
        a=k; b=k;
        if(k==0)
        {
            c=min(c,1);
            d=min(d,1);
        }
        k=min(c,d);
        if(k==0)
        {
            a=min(a,1);
            b=min(b,1);
        }
        c=k; d=k;
        cout<<(a+b+c+d)<<"\n";
        for(int i=0;i<a;i++) cout<<"L";
        for(int i=0;i<c;i++) cout<<"U";
        for(int i=0;i<b;i++) cout<<"R";
        for(int i=0;i<d;i++) cout<<"D";
        cout<<"\n";

    }
    return 0;
}