#include <bits/stdc++.h>
using namespace std;

double cosp[1007];
double sinp[1007];

double PI=3.14159265359;

struct odc
{
    double x;
    double y;
    int kat;
    odc()
    {

        x=y=0.0;
        kat=0;
    }
    odc(double xx, double yy, int katkat)
    {
        kat=katkat;
        x=(xx*cosp[kat]-yy*sinp[kat]);
        y=(xx*sinp[kat]+yy*cosp[kat]);
    }
};

odc operator + (odc a, odc b)
{
    odc ret=odc();
    ret.kat=(a.kat+b.kat)%360;
    ret.x=a.x+(b.x*cosp[a.kat]-b.y*sinp[a.kat]);
    ret.y=a.y+(b.x*sinp[a.kat]+b.y*cosp[a.kat]);
    return ret;
};

int n, m;

int kont[1000007];
double dlu[1000007];

int typ;
int kt;
int ile;

int n1;
odc drzewo[1100007];

void pisz(int v, odc war)
{
    v+=n1-1;
    drzewo[v]=war;
    v>>=1;
    while(v)
    {
        drzewo[v]=drzewo[v<<1]+drzewo[(v<<1)^1];
        v>>=1;
    }
}

odc czyt(int v, int a, int b, int graa, int grab)
{
    if (a>=graa && b<=grab)
    {
        return drzewo[v];
    }
    if (a>grab || b<graa)
    {
        return odc();
    }
    return czyt((v<<1), a, (a+b)>>1, graa, grab)+czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab);
}

int main()
{
    for (int i=0; i<360; i++)
    {
        cosp[i]=cos(i*PI/180.0);
        sinp[i]=sin(i*PI/180.0);
    }
    scanf("%d%d", &n, &m);
    n1=1;
    while(n1<n)
    n1<<=1;
    for (int i=1; i<=n; i++)
    {
        kont[i]=0;
        dlu[i]=1.0;
        pisz(i, odc(1.0, 0.0, 0));
    }
    //printf("%.9lf %.9lf\n", (odc(1.0, 0.0, 90)+odc(1.0, 0.0, 90)).x, (odc(1.0, 0.0, 90)+odc(1.0, 0.0, 90)).y);
    while(m--)
    {
        scanf("%d%d%d", &typ, &kt, &ile);
        if (typ==1)
        {
            dlu[kt]+=ile;
        }
        else
        {
            kont[kt]-=ile;
            kont[kt]+=360;
            kont[kt]%=360;
        }
        /*for (int i=1; i<=n; i++)
        {
            printf("%d %.6lf\n", i, dlu[i]);
        }*/
        pisz(kt, odc(dlu[kt], 0.0, kont[kt]));
        //printf("%.9lf %.9lf\n", czyt(1, 1, n1, 1, 1).x, czyt(1, 1, n1, 1, 1).y);
        printf("%.9lf %.9lf\n", drzewo[1].x, drzewo[1].y);
    }
    return 0;
}