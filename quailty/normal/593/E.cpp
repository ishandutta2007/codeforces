#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int d[5][2]={{0,0},{0,1},{1,0},{0,-1},{-1,0}};
const int Mod=1000000007;
struct Matrix
{
    int a[20][20];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<20;i++)a[i][i]=1;
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
                for(int k=0;k<20;k++)
                    C.a[i][j]=(C.a[i][j]+1LL*a[i][k]*B.a[k][j])%Mod;
        return C;
    }
    Matrix operator ^ (const int &t)const
    {
        int p=t;
        Matrix A=(*this),res;
        res.init();
        while(p)
        {
            if(p&1)res=res*A;
            A=A*A;
            p>>=1;
        }
        return res;
    }
};
int get(int x,int y,int n,int m)
{
    return (x-1)*m+(y-1);
}
int cat[20][20];
int main()
{
    int n,m,q,la=1;
    scanf("%d%d%d",&n,&m,&q);
    Matrix res,now;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<5;k++)
            {
                int ti=i+d[k][0];
                int tj=j+d[k][1];
                if(ti>=1 && ti<=n && tj>=1 && tj<=m)
                    now.a[get(i,j,n,m)][get(ti,tj,n,m)]++;
            }
    res.init();
    while(q--)
    {
        int tp,x,y,t;
        scanf("%d%d%d%d",&tp,&x,&y,&t);
        res=res*(now^(t-la)),la=t;
        if(tp==1)printf("%d\n",res.a[get(1,1,n,m)][get(x,y,n,m)]);
        else
        {
            if(tp==3)cat[x][y]=0;
            for(int k=0;k<5;k++)
            {
                int tx=x+d[k][0];
                int ty=y+d[k][1];
                if(tx>=1 && tx<=n && ty>=1 && ty<=m && cat[tx][ty]==0)
                {
                    now.a[get(x,y,n,m)][get(tx,ty,n,m)]=tp-2;
                    now.a[get(tx,ty,n,m)][get(x,y,n,m)]=tp-2;
                }
            }
            if(tp==2)cat[x][y]=1;
        }
    }
    return 0;
}