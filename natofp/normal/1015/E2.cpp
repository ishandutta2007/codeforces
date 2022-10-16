#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char tab[1001][1001];
int s1[1001][1001];
int s2[1001][1001];
int s3[1001][1001];
int s4[1001][1001];
int s[1001][1001];
int h[1001][1001];

void prawo(int n,int m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            if(j==m)
            {
                if(tab[i][j]=='*') s1[i][j]=1;
                else s1[i][j]=0;
            }
            else
            {
                if(tab[i][j]=='*') s1[i][j]=s1[i][j+1]+1;
                else s1[i][j]=0;
            }
        }
    }
}

void gora(int n,int m)
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==1)
            {
                if(tab[j][i]=='*') s2[j][i]=1;
                else s2[j][i]=0;
            }
            else
            {
                if(tab[j][i]=='*') s2[j][i]=s2[j-1][i]+1;
                else s2[j][i]=0;
            }
        }
    }
}

void lewo(int n,int m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j==1)
            {
                if(tab[i][j]=='*') s3[i][j]=1;
                else s3[i][j]=0;
            }
            else
            {
                if(tab[i][j]=='*') s3[i][j]=1+s3[i][j-1];
                else s3[i][j]=0;
            }

        }
    }
}


void dol(int n,int m)
{
    for(int i=1;i<=m;i++)
    {
        for(int j=n;j>=1;j--)
        {
            if(j==n)
            {
                if(tab[j][i]=='*') s4[j][i]=1;
                else s4[j][i]=0;
            }
            else
            {
                if(tab[j][i]=='*') s4[j][i]=1+s4[j+1][i];
                else s4[j][i]=0;
            }
        }
    }
}

struct gwiazda
{
    int x;
    int y;
    int ray;
};

int promien(int a,int b,int c,int d)
{
    int odp=20000;
    if(a<odp) odp=a;
    if(b<odp) odp=b;
    if(c<odp) odp=c;
    if(d<odp) odp=d;
    return odp;
}


int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
    vector<gwiazda> odp;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>tab[i][j];
        }
    }

    prawo(n,m);
    gora(n,m);
    dol(n,m);
    lewo(n,m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            gwiazda nowa;
            nowa.x=i;
            nowa.y=j;
            nowa.ray=promien(s1[i][j],s2[i][j],s3[i][j],s4[i][j])-1;
            if(nowa.ray>0) odp.push_back(nowa);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            s[i][j]=0;
            h[i][j]=0;
        }
    }
    for(int i=0;i<odp.size();i++)
    {
        int x=odp[i].x;
        int y=odp[i].y;
        int ray=odp[i].ray;
        s[x][y-ray]++;
        if(y+ray+1<=m) s[x][y+ray+1]--;
        h[x-ray][y]++;
        if(x+ray+1<=n) h[x+ray+1][y]--;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=m;j++)
        {
            s[i][j]+=s[i][j-1];
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=2;j<=n;j++)
        {
            h[j][i]+=h[j-1][i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(tab[i][j]=='*')
            {
                if(s[i][j]==0 && h[i][j]==0) {cout<<"-1"; return 0;}
            }
        }
    }
    int k=odp.size();
    cout<<k<<endl;
    for(int i=0;i<k;i++)
    {
        cout<<odp[i].x<<" "<<odp[i].y<<" "<<odp[i].ray<<"\n";
    }






    return 0;
}