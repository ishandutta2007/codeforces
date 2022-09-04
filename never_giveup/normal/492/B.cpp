#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int n,l;
    cin>>n>>l;
    int a[1000],q[1000];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<n;i++)
        q[i-1]=a[i]-a[i-1];
    double m=n>1?*max_element(q,q+(n-1)):0;
    m/=2.0;
    if(m<a[0])
        m=a[0];
    if(m<l-a[n-1])
        m=l-a[n-1];
    cout<<setprecision(20)<<m;
}