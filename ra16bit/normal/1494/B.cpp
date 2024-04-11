#include <bits/stdc++.h>
using namespace std;
int t,n,u,r,d,l,ul,ur,dl,dr;
bool ok;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d%d%d%d",&n,&u,&r,&d,&l);
    for (ok=ul=0; ul<2; ul++) for (ur=0; ur<2; ur++) 
      for (dl=0; dl<2; dl++) for (dr=0; dr<2; dr++) {
        if (ul+ur>u || n-2+ul+ur<u) continue;
        if (dl+dr>d || n-2+dl+dr<d) continue;
        if (ul+dl>l || n-2+ul+dl<l) continue;
        if (dr+ur>r || n-2+dr+ur<r) continue;
        ok=true;
      }
    puts(ok?"YES":"NO");
  }
  return 0;
}