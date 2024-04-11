#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=555;
char p[nax][nax];
int h,w;

bool ok (int h1,int w1)
{
    if(h1==1 || h1==h || w1==1 || w1==w) return false;
    if(p[h1+1][w1]!='*') return false;
    if(p[h1-1][w1]!='*') return false;
    if(p[h1][w1+1]!='*') return false;
    if(p[h1][w1-1]!='*') return false;
    return true;
}

bool juz = false;

void zrob(int h1,int w1)
{
    int x=h1;
    int y=w1;
    juz=true;
    while(h1<=h && (p[h1][w1]=='*' || p[h1][w1]=='x'))
    {
        p[h1][w1]='x';
        h1++;
    }
    h1=x;
    w1=y;
    while(h1>=1 && (p[h1][w1]=='*' || p[h1][w1]=='x'))
    {
        p[h1][w1]='x';
        h1--;
    }
    h1=x;
    w1=y;
    while(w1<=w && (p[h1][w1]=='*' || p[h1][w1]=='x'))
    {
        p[h1][w1]='x';
        w1++;
    }
    h1=x;
    w1=y;
    while(w1>=1 && (p[h1][w1]=='*' || p[h1][w1]=='x'))
    {
        p[h1][w1]='x';
        w1--;
    }
    h1=x;
    w1=y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>h>>w;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            cin>>p[i][j];
        }
    }
    for(int i=1;i<=h;i++)
    {
        if(juz==true) break;
        for(int j=1;j<=w;j++)
        {
            bool xd=ok(i,j);
            if(xd==false) continue;
            zrob(i,j);
            break;

        }
        if(juz==true) break;
    }
    if(juz==false)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(p[i][j]=='*')
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
    return 0;
}