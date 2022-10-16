#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct odcinek
{
    int x1,x2;
    int y1,y2;
};
const int N=1005;
odcinek tab[N];

long long int delta(long long int a,long long int b,long long int c,long long int d)
{
    return (a*d-b*c);
}

bool in(long long int l,long long int r,long long int x)
{
    if(l>r) swap(l,r);
    if(x>=l && x<=r) return true;
    return false;
}

bool czy(odcinek a,odcinek b,int &x,int &y)
{
    long long int a1,a2,b1,b2,c1,c2;
    a1=a.y1-a.y2;
    b1=a.x2-a.x1;
    a2=b.y1-b.y2;
    b2=b.x2-b.x1;
    c1=-a1*a.x1-b1*a.y1;
    c2=-a2*b.x1-b2*b.y1;
    if(delta(a1,b1,a2,b2)==0) return false;
    long long int wx,wy,w;
    wx=delta(-c1,b1,-c2,b2);
    wy=delta(a1,-c1,a2,-c2);
    w=delta(a1,b1,a2,b2);
    if(wx%w!=0 || wy%w!=0)
    {
        return false;
    }
    x=wx/w;
    y=wy/w;
    if(!in(a.x1,a.x2,x) || !in(b.x1,b.x2,x)) return false;
    if(!in(a.y1,a.y2,y) || !in(b.y1,b.y2,y)) return false;
    return true;

}

int gcd(int a,int b)
{
    while(b)
    {
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int ilosc(odcinek a)
{
    int x=abs(a.x1-a.x2);
    int y=abs(a.y1-a.y2);
    return gcd(x,y)+1;
}


int main()
{
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tab[i].x1>>tab[i].y1>>tab[i].x2>>tab[i].y2;
    }
    int ans=0;
    int x,y;

    for(int i=0;i<n;i++)
    {
        odcinek a=tab[i];
        ans+=ilosc(a);
         set<pair<int,int> > pkt;
        for(int j=0;j<i;j++)
        {
            if(czy(a,tab[j],x,y)) pkt.insert(make_pair(x,y));
        }
        ans-=pkt.size();
    }
    cout<<ans;
    return 0;
}