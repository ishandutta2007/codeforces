#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int p[8][2],q[8][2];
int x[8],y[8],t[4];
int main()
{
    for(int i=0;i<8;i++)
    {
        scanf("%d%d",&p[i][0],&p[i][1]);
        x[i]=p[i][0];
        y[i]=p[i][1];
    }
    sort(x,x+8);
    int tx=unique(x,x+8)-x;
    sort(y,y+8);
    int ty=unique(y,y+8)-y;
    if(tx!=2 || ty!=2)return 0*printf("NO");
    for(int i=0;i<4;i++)
    {
        q[i*2][0]=x[i/2];
        q[i*2][1]=y[(i%2)^(i/2)];
    }
    for(int i=0;i<4;i++)
        for(int j=0;j<2;j++)
            q[(i*2+3)%8][j]=q[i*2][j];
    bool isok=0;
    for(int i=0;i<4;i++)t[i]=i;
    do
    {
        bool flag=1;
        for(int i=0;i<4;i++)
        {
            bool check=0;
            if(p[t[i]*2][0]==q[i*2][0] && p[t[i]*2][1]==q[i*2][1]
            && p[t[i]*2+1][0]==q[i*2+1][0] && p[t[i]*2+1][1]==q[i*2+1][1])check=1;
            if(p[t[i]*2][0]==q[i*2+1][0] && p[t[i]*2][1]==q[i*2+1][1]
            && p[t[i]*2+1][0]==q[i*2][0] && p[t[i]*2+1][1]==q[i*2][1])check=1;
            if(!check)flag=0;
        }
        if(flag)isok=1;
    }while(next_permutation(t,t+4));
    return 0*printf("%s",(isok ? "YES" : "NO"));
}