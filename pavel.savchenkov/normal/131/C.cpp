#include <cstdio>
#include <cstring>
#define ll long long

using namespace std;

ll k (ll n, ll k) {
    if (n<k) return 0;
    double res = 1;
    for (ll i=1; i<=k; ++i)
        res = res * (n-k+i) / i;
    return (ll) (res + 0.01);
}

int main() {
 ll n,m,t;
 scanf("%I64d%I64d%I64d",&n,&m,&t);
 ll res=0;
 for (ll i=4;i<=t-1;i++)
 {
  res+=k(n,i)*k(m,t-i);
 }
 printf("%I64d",res);
 return 0;
 }