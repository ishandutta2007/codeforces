#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int tx[10]={3,0,0,0,1,1,1,2,2,2};
const int ty[10]={1,0,1,2,0,1,2,0,1,2};
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char s[15];
int x[15],y[15],nx[15],ny[15];
bool check(int n,int k)
{
    for(int i=0;i<n;i++)
    {
        nx[i]=x[i]+d[k][0];
        ny[i]=y[i]+d[k][1];
    }
    for(int i=0;i<n;i++)
    {
        if(nx[i]==3)
        {
            if(ny[i]!=1)return 0;
        }
        else if(nx[i]>=0 && nx[i]<=2)
        {
            if(ny[i]<0 || ny[i]>=3)return 0;
        }
        else return 0;
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++)
    {
        x[i]=tx[s[i]-'0'];
        y[i]=ty[s[i]-'0'];
    }
    for(int i=0;i<4;i++)
        if(check(n,i))return 0*printf("NO\n");
    return 0*printf("YES\n");
}