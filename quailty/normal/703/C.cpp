#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long double db;
const int MAXN=10005;
const db eps=1e-9;
int sgn(db x)
{
    if(x>eps)return 1;
    if(x<-eps)return -1;
    return 0;
}
struct Point
{
    db x,y;
    void input()
    {
        cin>>x>>y;
    }
}p[MAXN];
bool check(db u,db v,db t,int n,int ty)
{
    for(int i=0;i<n;i++)
        if(ty*sgn(u*p[i].x-v*p[i].y-u*v*t)<0)return 0;
    return 1;
}
int main()
{
    int n;
    db w,v,u;
    cin>>n>>w>>v>>u;
    for(int i=0;i<n;i++)
        p[i].input();
    cout<<fixed<<setprecision(12);
    if(check(u,v,0,n,1))cout<<w/u<<endl;
    else
    {
        db l=0,r=2e9;
        for(int _=0;_<100;_++)
        {
            db m=(l+r)/2;
            if(check(u,v,m,n,-1))r=m;
            else l=m;
        }
        cout<<w/u+(l+r)/2<<endl;
    }
    return 0;
}