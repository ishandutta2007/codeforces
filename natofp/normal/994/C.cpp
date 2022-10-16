#include <iostream>
#include <bits/stdc++.h>

using namespace std;


struct punkt
{
    int x;
    int y;
};

bool sprawdz(punkt a,punkt b,punkt c,punkt d)
{
    //y=px+r;
    if(a.x==b.x)
    {
        int p=1; if(c.y>d.y && c.x<d.x) p=-1;
        if(d.y>c.y && d.x<c.x) p=-1;
        int r=c.y-p*c.x;
        int y=p*a.x+r;
        if(y>=min(a.y,b.y) && y<=max(a.y,b.y) && min(c.x,d.x)<=a.x && max(c.x,d.x)>=a.x) return true;
    }
    if(a.y==b.y)
    {
        int p=1; if(c.y>d.y && c.x<d.x) p=-1;
        if(d.y>c.y && d.x<c.x) p=-1;
        int r=c.y-p*c.x;
        int x=(a.y-r)/p;
        if(x>=min(a.x,b.x) && x<=max(a.x,b.x) && min(c.y,d.y)<=a.y && max(c.y,d.y)>=a.y)  return true;
    }
    return false;

}


int main()
{
    punkt * a;
    a=new punkt[4];
    for(int i=0;i<4;i++)
        cin>>a[i].x>>a[i].y;
    punkt * b;
    b=new punkt[4];
    for(int i=0;i<4;i++)
    cin>>b[i].x>>b[i].y;
    int prawo,lewo,gora,dol,prawo1,lewo1,gora1,dol1;
    prawo=-100; prawo1=-100;
    lewo=100;   lewo1=100;
    gora=-100;  gora1=-100;
    dol=100;    dol1=100;
    for(int i=0;i<4;i++)
    {
        if(a[i].y>gora) gora=a[i].y;
    }
    for(int i=0;i<4;i++)
    {
        if(a[i].y<dol) dol=a[i].y;
    }
    for(int i=0;i<4;i++)
    {
        if(a[i].x>prawo) prawo=a[i].x;
    }
    for(int i=0;i<4;i++)
    {
        if(a[i].x<lewo) lewo=a[i].x;
    }
    for(int i=0;i<4;i++)
    {
        if(b[i].y>gora1) gora1=b[i].y;
    }
    for(int i=0;i<4;i++)
    {
        if(b[i].y<dol1) dol1=b[i].y;
    }
    for(int i=0;i<4;i++)
    {
        if(b[i].x>prawo1) prawo1=b[i].x;
    }
    for(int i=0;i<4;i++)
    {
        if(b[i].x<lewo1) lewo1=b[i].x;
    }
    if(gora>=gora1 && dol<=dol1 && prawo>=prawo1 && lewo <= lewo1) {cout<<"YES"; return 0;}

    else
    {
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
        {
            if(sprawdz(a[i],a[(i+1)%4],b[j],b[(j+1)%4])) {cout<<"YES"; return 0;}
        }
    }
    if(prawo1>=prawo && lewo1<=lewo && gora1>=gora && dol1<=dol)
    {
        int x,y;
        x=a[0].x;
        y=a[0].y;
        int OX,OY;
        for(int i=0;i<4;i++)
        {
            if(b[i].x==prawo1)  OX=b[i].y;
            if(b[i].y==dol1)     OY=b[i].x;
        }
        int spr=0;
        if(x>=OY && y>=OX) spr=1;
        else if(x>=OY && y<=OX) spr=2;
        else if(x<=OY && y>=OX) spr=3;
        else if(x<=OY && y<=OX) spr=4;
        if(spr==1 && (y-OX)+(x-OY)<=(gora1-OX)) {cout<<"YES"; return 0;}
        if(spr==2 && (OX-y)+(x-OY)<=OX-dol1) {cout<<"YES"; return 0;}
        if(spr==3 && (y-OX)+(OY-x)<=(gora1-OX)) {cout<<"YES"; return 0;}
        if(spr==4 && (OX-y)+(OY-x)<=(OX-dol1)) {cout<<"YES"; return 0;}

    }
    cout<<"NO";
    return 0;
}