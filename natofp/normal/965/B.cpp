#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=101;
char plansza[N][N];
int wynik[N][N];
void czysc()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            wynik[i][j]=0;
        }
    }
}

void mark(int x,int y,int i,int k)
{
    if(i==1)
    {
        for(int i=x;i<x+k;i++)
        {
            wynik[i][y]++;
        }
    }
    else
    {
        for(int i=y;i<y+k;i++)
        {
            wynik[x][i]++;
        }
    }
}

bool czy(int x,int y,int k,int n)
{
    bool a,b;
    a=true; b=true;
    for(int i=x;i<x+k;i++)
    {
        if(i>=n) a=false;
        if(plansza[i][y]=='#') a=false;
    }
    for(int i=y;i<y+k;i++)
    {
        if(i>=n) b=false;
        if(plansza[x][i]=='#') b=false;
    }
    if(a) mark(x,y,1,k);
    if(b) mark(x,y,2,k);
}



int main()
{
    int n,k;
    cin>>n>>k;
    czysc();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>plansza[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            czy(i,j,k,n);
        }
    }
    int naj=0;
    int x=0;
    int y=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(wynik[i][j]>naj)
            {
                naj=wynik[i][j]; x=i; y=j;
            }
        }
    }
    cout<<x+1<<" "<<y+1;
    return 0;
}