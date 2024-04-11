#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct lair
{
    float x;
    float y;
};
vector<lair> a;

bool czy(double r,int n)
{
    double maxleft,maxright;
    maxleft=-1e9;
    maxright=1e9;
    for(int i=0;i<n;i++)
    {
        double x=a[i].x;
        double y=a[i].y;
        double t=2*y*r-y*y;
        t=sqrt(t);
        maxleft=max(maxleft,x-t);
        maxright=min(maxright,x+t);

    }
    if(maxleft<=maxright) return true;
    return false;
}

double BS(double x,double y,int n)
{

    for(int i=0;i<80;i++)
    {

        double mid=(x+y)/2;
        if(czy(mid,n)==true)
        {
            y=mid;
        }
        else
        {
            x=mid;
        }
    }
    return y;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        float x,y;
        cin>>x>>y;
        lair xd;
        xd.x=x;
        xd.y=y;
        a.push_back(xd);
    }
    for(int i=0;i<n-1;i++)
    {
        bool xd=true;
        if(a[i].y<0 && a[i+1].y>0) xd=false;
        if(a[i].y>0 && a[i+1].y<0) xd=false;
        if(xd==false) {cout<<-1; return 0;}
    }
    for(int i=0;i<n;i++)
    {
        if(a[i].y<0) a[i].y*=-1;
    }
    float maxy=a[0].y;
    float maxx=a[0].x;
    for(int i=1;i<n;i++) {maxy=max(maxy,a[i].y);}

    cout<<setprecision(20)<<BS(maxy*0.5,1e16,n);


    return 0;
}