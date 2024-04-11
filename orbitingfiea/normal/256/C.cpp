#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;

int f[1001000],n=1000000,pre[1001000];
bitset<66>b;
ll a[101000],ans=0;

int main(){
  ios::sync_with_stdio(false);
  f[1]=0; pre[1]=1;
  ll l=1,r=1;
  for (int i=2;i<=n;++i){
    if (l*l*l*l<i) ++l;
    if ((r+1)*(r+1)<=i) ++r;
    b.reset();
    for (int j=r;j>=l;j=pre[j]) b[f[j]]=1;
    for (;b[f[i]];) ++f[i];
    pre[i]= f[i]==f[i-1]? pre[i-1]: i-1;
  }
  cin>>n;
  for (int i=1;i<=n;++i) cin>>a[i];
  sort(a+1,a+n+1);
  l=2; r=1;
  for (int I=1;I<=n;++I){
    ll i=a[I],res=0;
    while (l*l*l*l<i) ++l;
    while ((r+1)*(r+1)<=i) ++r;
    b.reset();
    for (int j=r;j>=l;j=pre[j]) b[f[j]]=1;
    for (;b[res];) ++res;
    ans^=res;
  }
  cout<<(ans?"Furlo":"Rublo");
}