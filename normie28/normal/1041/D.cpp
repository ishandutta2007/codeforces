#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define END return
ll l[200002],r[200002];
ll n,k,x,i,j,maxx=0;
int main()
{
cin>>n>>k;
for (i=0;i<n;i++) {cin>>l[i]>>r[i]; }
for (ll i=0;i<n;i++) {
if (i) k+=l[i]-r[i-1];
while ((k>l[j+1]-r[j])and(j+1<n)) {k-=l[j+1]-r[j];j++;}
if (maxx<r[j]-l[i]+k) maxx=r[j]-l[i]+k;
}
cout<<maxx;
}