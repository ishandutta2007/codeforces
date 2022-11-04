#include<bits/stdc++.h>
using namespace std;

typedef double db;

const int MAXN=205;

struct Matrix
{
    db a[MAXN][MAXN];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<MAXN;i++)
            for(int j=0;j<MAXN;j++)
                a[i][j]=1.0*(i==j);
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<MAXN;i++)
            for(int k=0;k<MAXN;k++)
                for(int j=0;j<MAXN;j++)
                    C.a[i][j]+=a[i][k]*B.a[k][j];
        return C;
    }
}big[105],sma[105];

struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    int operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
}p[MAXN];

bool vis[MAXN][MAXN];
vector<vector<int> > lines;
vector<int> belong[MAXN];

db val[MAXN],tmp[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(!vis[i][j])
            {
                vector<int> line;
                for(int k=0;k<n;k++)
                    if((p[k]-p[i])*(p[k]-p[j])==0)
                        line.push_back(k);
                for(auto &x:line)
                    belong[x].push_back((int)lines.size());
                for(auto &x:line)
                    for(auto &y:line)
                        vis[x][y]=1;
                lines.push_back(line);
            }
    sma[0].init();
    for(int i=0;i<n;i++)
        for(auto &t:belong[i])
        {
            db p=1.0/(int)belong[i].size()/(int)lines[t].size();
            for(auto &j:lines[t])
                sma[1].a[i][j]+=p;
        }
    for(int i=2;i<=100;i++)
        sma[i]=sma[i-1]*sma[1];
    big[0].init();
    big[1]=sma[100];
    for(int i=2;i<=100;i++)
        big[i]=big[i-1]*big[1];
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int t,m;
        scanf("%d%d",&t,&m);
        t--,m--;
        memset(val,0,sizeof(val));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                val[i]+=big[m/100].a[i][j]*sma[m%100].a[j][t];
        db res=0;
        for(auto &line:lines)
        {
            db now=0;
            for(auto &k:line)
                now+=val[k];
            now/=(int)line.size();
            res=max(res,now);
        }
        printf("%.12f\n",res);
    }
    return 0;
}