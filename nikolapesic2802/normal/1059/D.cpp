#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
#define MAX_SIZE 1000
const double ee=1e-6;
const double EPS = 1e-9;
struct PT
{
    double x,y;
    double length()
    {
        return sqrt(x*x+y*y);
    }
    int normalize()
    {
        double l = length();
        if(fabs(l)<EPS)
            return -1;
        x/=l;
        y/=l;
        return 0;
    }
    PT operator-(PT a)
    {
        PT r;
        r.x=x-a.x;
        r.y=y-a.y;
        return r;
    }
    PT operator+(PT a)
    {
        PT r;
        r.x=x+a.x;
        r.y=y+a.y;
        return r;
    }
    PT operator*(double sc)
    {
        PT r;
        r.x=x*sc;
        r.y=y*sc;
        return r;
    }
};
double dist(PT& a, PT& b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double trap(PT a, PT b)
{
    return (0.5*(b.x - a.x)*(b.y + a.y));
}
double triarea(PT a, PT b, PT c)
{
    return fabs(trap(a,b)+trap(b,c)+trap(c,a));
}
void closestpt( PT p1, PT p2, PT p3, PT &r )
{
    if( fabs( triarea( p1, p2, p3 ) ) < EPS )
    {
        r = p3;
        return;
    }
    PT v = p2-p1;
    v.normalize();
    double pr;
    pr = (p3.y-p1.y)*v.y + (p3.x-p1.x)*v.x;
    r = p1+v*pr;
}
int lineAndCircle(PT& oo, double r, PT& p1, PT& p2, PT& r1, PT& r2)
{
    PT m;
    closestpt(p1,p2,oo,m);
    PT v = p2-p1;
    v.normalize();
    double r0=dist(oo, m);
    if(r0>r+EPS)
        return -1;
    if(fabs(r0-r)<EPS)
    {
        r1=r2=m;
        return 1;
    }
    double dd = sqrt(r*r-r0*r0);
    r1 = m-v*dd;
    r2 = m+v*dd;
    return 0;
}

vector<PT> points;
bool pokusaj(double d)
{
    PT p1,p2,r1,r2;
    p1.x=0;
    p1.y=d;
    p2.x=1;
    p2.y=d;
    double minn=LLONG_MIN,maxx=LLONG_MAX;
    for(int i=0; i<points.size(); i++)
    {
        //printf("%f %f\n",points[i].x,points[i].y);
        int t=lineAndCircle(points[i],d,p1,p2,r1,r2);
        //printf("Presek 1: %lf, presek 2: %lf  %i\n",r1.x,r2.x,t);
        if(t==-1)
        {
            return false;
        }
        double m1=min(r1.x,r2.x);
        double m2=max(r1.x,r2.x);
        minn=max(minn,m1);
        maxx=min(maxx,m2);
    }
    if(minn>maxx)
    {
        return false;
    }
    return true;
}
int main()
{
    int n;
    scanf("%i",&n);
    int koji=0;
    for(int i=0; i<n; i++)
    {
        int x,y;
        scanf("%i %i",&x,&y);
        PT p;
        p.x=x;
        p.y=abs(y);
        points.pb(p);
        if(koji==0)
        {
            if(y<0)
            {
                koji=-1;
            }
            else
            {
                koji=1;
            }
        }
        else
        {
            if(y*koji<0)
            {
                printf("-1\n");
                return 0;
            }
        }
    }
    double a=0;
    double b=1e14+5;
    while(fabs(a-b)/max((double)1,fabs(a))>ee)
    {
        double m=(a+b)/2;
        //printf("Pokusavam %f:  %f, %f",m,a,b);
        if(pokusaj(m))
        {
            //printf("Uspeo!\n");
            b=m;
        }
        else
        {
            //printf("Neuspesno!\n");
            a=m;
        }
    }
    //a
    printf("%.10f\n",b);
    return 0;
}