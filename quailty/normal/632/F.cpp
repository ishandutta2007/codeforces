#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=2505;
int a[MAXN][MAXN];
struct node
{
    int x,y,d;
    node(){}
    node(int _x,int _y,int _d):x(_x),y(_y),d(_d){}
    bool operator < (const node &t)const
    {
        return d<t.d;
    }
}q[MAXN*MAXN];
bitset<MAXN>b[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++)
        if(a[i][i])
            return 0*printf("NOT MAGIC");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i][j]!=a[j][i])
                return 0*printf("NOT MAGIC");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            q[i*n+j]=node(i,j,a[i][j]);
    sort(q,q+n*n);
    int l=0;
    for(int i=0;i<n*n;i++)
    {
        while(l<n*n && q[l].d<q[i].d)
        {
            b[q[l].x][q[l].y]=1;
            l++;
        }
        if((b[q[i].x]&b[q[i].y]).any())
            return 0*printf("NOT MAGIC");
    }
    return 0*printf("MAGIC");
}