#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define end return
ll gcd(ll a, ll b)
{
if (!(a*b)) end a+b;
else if (a>b) end gcd(a%b,b); else end gcd(b%a,a);
}
int main()
{
ll n,p,w,d,x,y,z,g;
cin>>n>>p>>w>>d;
g=gcd(d,w);
if (p%g) {cout<<-1; end 0;}
y=0;
while ((p-y*d)%w) y++;
x=(p-y*d)/w;
z=n-x-y;
if ((x<0)or(z<0)) {cout<<-1; end 0;}
else cout<<x<<' '<<y<<' '<<z;
}