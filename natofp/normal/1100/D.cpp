#include <iostream>
#include <bits/stdc++.h>
using namespace std;

pair<int,int> a[666];
bool plansza[1111][1111];

void dokoncz(int x,int y)
{
    vector<pair<int,int> > wolne;
    for(int i=x-1;i<=x+1;i++)
    {
        for(int j=y-1;j<=y+1;j++)
        {
            if(i==x && j==y) continue;
            if(i<1 || i>999 || j<1 || j>999) continue;
            if(plansza[i][j]==false) wolne.push_back({i,j});
        }
    }
    for(int i=0;i<wolne.size();i++)
    {
        int x=wolne[i].first;
        int y=wolne[i].second;
        for(int j=0;j<666;j++)
        {
            if(a[j].first==x || a[j].second==y)
            {
                cout<<x<<" "<<y<<endl;
                fflush(stdout);
                exit(0);
            }
        }
    }
}

bool sprawdz(int x,int y)
{
    for(int i=0;i<666;i++)
    {
        if(a[i].first==x || a[i].second==y) return true;
    }
    return false;
}

void skoncz(int dx,int dy)
{
        int x=500; int y=500;
        while(1)
        {
        int pion,poziom;
        if(x<dx) poziom=1;
        else if(x==dx) poziom=0;
        else poziom=-1;
        if(y<dy) pion=1;
        else if(y==dy) pion=0;
        else pion=-1;
        if(plansza[x+poziom][y+pion]==false)
        {
            x+=poziom;
            y+=pion;
            cout<<x<<" "<<y<<endl;
            fflush(stdout);
            bool ok=sprawdz(x,y);
            if(ok) {exit(0);}
        }
        else
        {
            dokoncz(x,y);
            exit(0);
        }
        int k,dxx,dyy;
        cin>>k>>dxx>>dyy;
        if(k==dxx && dxx==dyy && k==-1) {exit(0);}
        k--;
        plansza[a[k].first][a[k].second]=false;
        plansza[dxx][dyy]=true;
        a[k].first=dxx;
        a[k].second=dyy;
        }


}

int main()
{
    int x,y;
    cin>>x>>y;
    memset(plansza,false,sizeof plansza);
    for(int i=0;i<666;i++)
    {
        cin>>a[i].first>>a[i].second;
        plansza[a[i].first][a[i].second]=true;
    }
    while(x!=500 || y!=500)
    {
        int pion,poziom;
        if(x<500) poziom=1;
        else if(x==500) poziom=0;
        else poziom =-1;
        if(y<500) pion=1;
        else if(y==500) pion=0;
        else pion=-1;
        if(plansza[x+poziom][y+pion]==false)
        {
            x+=poziom;
            y+=pion;
            cout<<x<<" "<<y<<endl;
            fflush(stdout);
            bool ok=sprawdz(x,y);
            if(ok) {return 0;}
        }
        else
        {
            dokoncz(x,y);
            return 0;
        }
        int k,dx,dy; cin>>k>>dx>>dy;
        if(k==dx && dx==dy && k==-1) {return 0;}
        k--;
        plansza[a[k].first][a[k].second]=false;
        plansza[dx][dy]=true;
        a[k].first=dx;
        a[k].second=dy;

    }
    int s[4];
    memset(s,0,sizeof s);
    for(int i=0;i<666;i++)
    {
        if(a[i].first<500 && a[i].second<500) s[0]++;
        else if(a[i].first<500 && a[i].second>500) s[1]++;
        else if(a[i].first>500 && a[i].second>500) s[2]++;
        else s[3]++;
    }

            if(s[0]<=167) skoncz(999,999);
            else if(s[1]<=167) skoncz(999,1);
            else if(s[2]<=167) skoncz(1,1);
            else skoncz(1,999);





    return 0;
}