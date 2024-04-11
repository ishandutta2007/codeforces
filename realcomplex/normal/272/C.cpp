#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  int n;
  scanf("%d",&n);
  ll h[n];
  for(int i = 0;i<n;i++)scanf("%lld",&h[i]);
  ll ans = 0,hl = 0;
  int wl;
  ll hc;
  int wc;
  int m;
  scanf("%d",&m);
  while(m--){
    scanf("%i %lld",&wc,&hc);
    ans = max(ans + hl,h[wc-1]);
    printf("%lld\n",ans);
    hl = hc,wl = wc;
  }
  return 0;
}