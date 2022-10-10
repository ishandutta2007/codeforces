#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int i,j,n;
vector <int> a;
vector <long long> f;
int main() {
  scanf("%d",&n);
  for (i=1; i*i<=n; i++) if (n%i==0) {
    a.push_back(i);
    if (i*i!=n) a.push_back(n/i);
  }
  sort(a.begin(),a.end());
  for (i=0; i<a.size(); i++) {
    f.push_back(0);
    for (j=0; j<i; j++) if (a[i]%a[j]==0) f[i]=max(f[i],f[j]);
    f[i]+=a[i];
  }
  printf("%I64d\n",f.back());
  return 0;
}