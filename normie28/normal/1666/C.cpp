#include <bits/stdc++.h>
using namespace std;
    int a,b,c,d,e,f,x,y;
int main() {
    cin>>a>>b>>c>>d>>e>>f;
    if (a>=c && a<=e) x=a;
    if (c>=a && c<=e) x=c;
    if (e>=a && e<=c) x=e;
    
    if (a>=e && a<=c) x=a;
    if (c>=e && c<=a) x=c;
    if (e>=c && e<=a) x=e;
    
    if (b>=d && b<=f) y=b;
    if (d>=f && d<=b) y=d;
    if (f>=b && f<=d) y=f;
    
    if (b>=f && b<=d) y=b;
    if (d>=b && d<=f) y=d;
    if (f>=d && f<=b) y=f;
    cout<<6<<endl;
    cout<<a<<' '<<b<<' '<<a<<' '<<y<<endl;
    cout<<x<<' '<<y<<' '<<a<<' '<<y<<endl;
    
    cout<<c<<' '<<d<<' '<<c<<' '<<y<<endl;
    cout<<x<<' '<<y<<' '<<c<<' '<<y<<endl;
    
    cout<<e<<' '<<f<<' '<<e<<' '<<y<<endl;
    cout<<x<<' '<<y<<' '<<e<<' '<<y<<endl;
}