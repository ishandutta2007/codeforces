#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=5e5+5;
int rozmiar=-1;
vector<int> t(N,0);
vector<int> t2(N,0);
vector<int> a;
struct wsk
{
    int a,b,c;
};
void build(int n)
{
    int xd=1;
    while(xd*2<n) xd*=2;
    xd*=2;
    rozmiar=xd;
}

void add(int a,int b,int c)
{
    int va=rozmiar+a;
    int vb=rozmiar+b;
    int x=c;
    t[va]|=x;
    if(vb!=va) t[vb]|=x;
    while(va/2!=vb/2)
    {
        if(va%2==0) t[va+1]|=x;
        if(vb%2==1) t[vb-1]|=x;
        va/=2; vb/=2;
    }

}

int query(int v)
{
    v+=rozmiar;
    int ans=0;
    ans|=t[v];
    while(v!=1)
    {
        v/=2;
        ans|=t[v];
    }
    return ans;
}

void build2(int n)
{
    for(int i=rozmiar;i<rozmiar+a.size();i++) t[i]=a[i-rozmiar];
    for(int i=rozmiar+a.size();i<=2*rozmiar-1;i++) t[i]=(1<<30)-1;
    for(int i=rozmiar-1;i>=1;i--)
    {
        t[i]=t[i*2]&t[i*2+1];
    }
}

int query2(int a,int b)
{
    int ans=(1<<30)-1;
    int va=rozmiar+a;
    int vb=rozmiar+b;
    ans&=t[va];
    if(va!=vb) ans&=t[vb];
    while(va/2!=vb/2)
    {
        if(va%2==0) ans&=t[va+1];
        if(vb%2==1) ans&=t[vb-1];
        va/=2; vb/=2;
    }
    return ans;
}

int main()
{
   int n,m; cin>>n>>m;
   build(n);
   wsk * tab=new wsk[m];
   for(int i=0;i<m;i++)
   {
       int x,y,z; cin>>x>>y>>z;
       x--; y--;
       wsk nowy; nowy.a=x; nowy.b=y; nowy.c=z;
       tab[i]=nowy;
       add(x,y,z);
   }
   for(int i=0;i<n;i++)
   {
       int t=query(i);
       a.push_back(t);
   }
   build2(n);
    for(int i=0;i<m;i++)
   {
       int x,y,z;
       x=tab[i].a;
       y=tab[i].b;
       z=tab[i].c;
       int t=query2(x,y);
       if(z!=t) {cout<<"NO"; return 0;}
   }
   cout<<"YES"<<endl;
   for(int i=0;i<n;i++) cout<<a[i]<<" ";


    return 0;
}