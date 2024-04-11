#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char tab[1005][1005];
bool czy[1005][1005];
void rob()
{
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1000;j++)
        {
            czy[i][j]=false;
        }
    }
}

bool zaznacz(int x,int y,int n,int m)
{
    if(x+2>=n || y+2>=m) return false;
    bool xd=true;
    for(int i=x;i<x+3;i++)
    {
        for(int j=y;j<y+3;j++)
        {
            if(i!=x+1 || j!=y+1)
            {
                if(tab[i][j]=='.') xd=false;
            }
        }
    }
    if(xd==false) return false;
    for(int i=x;i<x+3;i++)
    {
        for(int j=y;j<y+3;j++)
        {
            if(i!=x+1 || j!=y+1)
            {
                czy[i][j]=true;
            }
        }
    }

}


int main()
{
   int n,m;
   cin>>n>>m;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           cin>>tab[i][j];
       }
   }
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           zaznacz(i,j,n,m);
       }
   }
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(tab[i][j]=='#' && czy[i][j]==false) {cout<<"NO"; return 0;}
       }
   }
    cout<<"YES";

    return 0;
}