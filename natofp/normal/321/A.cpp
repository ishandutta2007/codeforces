#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string s;
int a,b;
int n;
long long int x=0;
long long int y=0;

bool symuluj()
{
    if(x==a && y==b) return true;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='U') y++;
        else if(s[i]=='D') y--;
        else if(s[i]=='R') x++;
        else x--;
        if(x==a && y==b) return true;
    }
    return false;
}

int main()
{
    cin>>a>>b;
    cin>>s;
    long long int TOP=0;
    long long int RIGHT=0;
    n=s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='U') TOP++;
        else if(s[i]=='D') TOP--;
        else if(s[i]=='R') RIGHT++;
        else RIGHT--;
    }
    if(RIGHT==0 && TOP==0)
    {
        if(symuluj()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return 0;
    }
    if(TOP!=0)
    {
        if(abs(b)<=100)
        {
            for(int i=0;i<=200;i++)
            {
                bool ok = symuluj();
                if(ok)
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
            cout<<"No"<<endl;
            return 0;
        }
        long long int xd=(long long int)TOP*b;
        if(xd<0)
        {
            cout<<"No"<<endl;
            return 0;
        }
        long long int ile=((abs(b)-100))/abs(TOP);
        y=TOP*ile;
        x=RIGHT*ile;
        for(int i=0;i<=1000;i++)
            {
                bool ok = symuluj();
                if(ok)
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
            cout<<"No"<<endl;
            return 0;

    }
    else
    {
        if(abs(a)<=100)
        {
            for(int i=0;i<=200;i++)
            {
                bool ok = symuluj();
                if(ok)
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
            cout<<"No"<<endl;
            return 0;
        }
        long long int xd=(long long int)RIGHT*a;
        if(xd<0)
        {
            cout<<"No"<<endl;
            return 0;
        }
        long long int ile=((abs(a)-100))/abs(RIGHT);
        y=TOP*ile;
        x=RIGHT*ile;
        for(int i=0;i<=1000;i++)
            {
                bool ok = symuluj();
                if(ok)
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
            cout<<"No"<<endl;
            return 0;
    }
    return 0;
}