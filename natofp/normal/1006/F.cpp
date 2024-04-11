#include <iostream>
#include <bits/stdc++.h>
#include<tr1/unordered_map>

using namespace std;

int n,m;
long long int k;
const int nax=22;
long long int a[nax][nax];
int polowa;
tr1::unordered_map<long long int,int> mapka[nax][nax];
long long int res=0;
void odgory(int x,int y,long long int value,int d)
{
    if(d==polowa)
    {
        mapka[x][y][value]++;
        return;
    }
    if(x+1<n) odgory(x+1,y,value^a[x+1][y],d+1);
    if(y+1<m) odgory(x,y+1,value^a[x][y+1],d+1);
    return;
}
void oddolu(int x,int y,long long int value,int d)
{
    if(d==n+m-2-polowa)
    {
        value=value^a[x][y];
        res+=mapka[x][y][value^k];
        return;
    }
    if(x-1>=0) oddolu(x-1,y,value^a[x-1][y],d+1);
    if(y-1>=0) oddolu(x,y-1,value^a[x][y-1],d+1);
    return;
}

int main()
{
    cin>>n>>m>>k;
    polowa=(n+m-2)/2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    odgory(0,0,a[0][0],0);
    oddolu(n-1,m-1,a[n-1][m-1],0);
    cout<<res<<endl;
    return 0;
}