#include<bits/stdc++.h>
using namespace std;

#define double long double

const int N=1e6+1e3+7,L=1e6;

struct areaEvent{
    double dA,dB,dC;
    int x;
};

struct connectionEvent{
    int u,v;
};

struct Query{
    int id,x;
};

vector<areaEvent>ae[N];

vector<connectionEvent>ce[N];

vector<Query>q[N];

int fa[N];

double A[N],B[N],C[N];

int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

int n,m;

struct P{
    long long x,y,z;
}p[N];

struct Vec{
    double x,y,z;
};

Vec operator -(const P &a,const P &b)
{
    return {(double)a.x-b.x,(double)a.y-b.y,(double)a.z-b.z};
}

Vec operator *(const Vec &a,double b)
{
    return {a.x*b,a.y*b,a.z*b};
}

Vec operator /(const Vec &a,double b)
{
    return a*(1.0/b);
}

double operator *(const Vec &a,const Vec &b)
{
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

double operator *(const P &a,const P &b)
{
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

double len(const Vec &a)
{
    return sqrt(a*a);
}

vector<int>sf[N];

vector<P>pt[N];

int a[N],b[N],c[N];

int Q;

double ans[N];

double sqr(double a)
{
    return a*a;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld%lld",&p[i].x,&p[i].y,&p[i].z);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        sf[a[i]].push_back(i);
        sf[b[i]].push_back(i);
        sf[c[i]].push_back(i);
        pt[i].push_back(p[a[i]]);
        pt[i].push_back(p[b[i]]);
        pt[i].push_back(p[c[i]]);
        sort(pt[i].begin(),pt[i].end(),[&](const P &a,const P &b){return a.z>b.z;});
    }
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
    {
        int h,x;
        scanf("%d%d",&h,&x);
        q[h].push_back({i,x});
    }
    for(int i=1;i<=m;i++)
    {
        auto p=pt[i];
        Vec v1=p[2]-p[0],v2=p[1]-p[0];
        double alp=acos(v1*v2/len(v1)/len(v2));
        v2=v2*(p[0].z-p[1].z)/(p[0].z-p[2].z);
        double c=0;
        if(p[0].z!=p[1].z)
        {
            c=0.5*len(v1)*len(v2)*sin(alp);
            ae[p[0].z].push_back({c/sqr(p[0].z-p[1].z),-c*2*p[0].z/sqr(p[0].z-p[1].z),c*sqr(p[0].z)/sqr(p[0].z-p[1].z),i});
            ae[p[1].z].push_back({-c/sqr(p[0].z-p[1].z),c*2*p[0].z/sqr(p[0].z-p[1].z),-c*sqr(p[0].z)/sqr(p[0].z-p[1].z),i});
        }
        Vec v3=p[0]-p[2],v4=p[1]-p[2];
        double bet=acos(v3*v4/len(v3)/len(v4));
        v3=v3*(p[1].z-p[2].z)/(p[0].z-p[2].z);
        double d=0;
        if(p[1].z!=p[2].z)
        {
            d=0.5*len(v3)*len(v4)*sin(bet);
            ae[p[1].z].push_back({-d/sqr(p[1].z-p[2].z),2*d*p[2].z/sqr(p[1].z-p[2].z),c+d-d*sqr(p[2].z)/sqr(p[1].z-p[2].z),i});
            ae[p[2].z].push_back({d/sqr(p[1].z-p[2].z),-2*d*p[2].z/sqr(p[1].z-p[2].z),-c-d+d*sqr(p[2].z)/sqr(p[1].z-p[2].z),i});
        }
        if(p[0].z==p[2].z)
        {
            c=0.5*len(p[2]-p[0])*len(p[1]-p[0])*sin(alp);
            d=0;
        }
        ae[p[2].z].push_back({0,0,c+d,i});
    }
    for(int i=1;i<=n+m;i++)
        fa[i]=i;
    for(int i=1;i<=n;i++)
        for(auto x:sf[i])
            ce[p[i].z].push_back({i+m,x});
    for(int i=L;i>=0;i--)
    {
        for(auto [dA,dB,dC,x]:ae[i])
        {
            int fx=find(x);
            // double pre=A[fx]*sqr(i-1)+B[fx]*(i-1)+C[fx];
            A[fx]+=dA,B[fx]+=dB,C[fx]+=dC;
            // double aft=A[fx]*sqr(i-1)+B[fx]*(i-1)+C[fx];
            // printf("%d %d %.5lf %.5lf\n",i,x,pre,aft);
        }
        for(auto [id,x]:q[i])
        {
            int fx=find(x+m);
            if(p[x] .z<=i)
                ans[id]=-1;
            else
                ans[id]=A[fx]*sqr(i)+B[fx]*i+C[fx];
        }
        for(auto [u,v]:ce[i])
        {
            int fu=find(u),fv=find(v);
            if(fu==fv)
                continue;
            fa[fv]=fu;
            A[fu]+=A[fv];
            B[fu]+=B[fv];
            C[fu]+=C[fv];
        }
    }
    for(int i=1;i<=Q;i++)
    {
        if(ans[i]<0)
            printf("-1\n");
        else
            printf("%.15Lf\n",ans[i]);
    }
}