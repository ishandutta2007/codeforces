#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
    int n;
    cin>>n;
    
    ll a[n+2],b[n+2];
    a[0]=0;
    b[n-1]=0;
    
    ll c[n],y=0;
    for(int i=0;i<n;i++) 
    {
        cin>>c[i];
    }
    
    ll ma=c[0];
    ll d[n],e[n];
    d[0]=ma;
    for(int i=1;i<n;i++)
    {
        a[i]=a[i-1]+max(y,ma+i-c[i]);
        ma=max(ma,c[i]-i);
        d[i]=ma+i;
    }
    ma=c[n-1];
    e[n-1]=ma;
    for(int i=n-2;i>=0;i--)
    {
        b[i]=b[i+1]+max(y,ma+(n-1-i)-c[i]);
        ma=max(ma,c[i]-(n-1-i));
        e[i]=ma+(n-1-i);
    }
    
    ll mi=LLONG_MAX;
    for(int i=0;i<n-1;i++)   
    {
        if(d[i]==e[i+1])        mi=min(mi,a[i]+b[i+1]+1);
        else                  mi=min(mi,a[i]+b[i+1]);
    }
    mi=min(mi,a[n-1]);
    mi=min(mi,b[0]);
    cout<<mi<<endl;
}