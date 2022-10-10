#include <cstdio>
#include <string>
#include <map>
using namespace std;
int n,i,j,x,N,b[1010];
map<string, int> m;
map<string, int>::iterator it;
string s,a[1010];
char st[22];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",st); s=st;
    scanf("%d",&x);
    m[s]=max(m[s],x);
  }
  for (it=m.begin(); it!=m.end(); it++) {
    a[N]=it->first;
    b[N++]=it->second;
  }
  printf("%d\n",N);
  for (i=0; i<N; i++) {
    for (j=x=0; j<N; j++) if (b[j]>b[i]) x++;
    printf("%s ",a[i].c_str());
    if (x*100>N*50) puts("noob"); else
     if (x*100>N*20) puts("random"); else
      if (x*100>N*10) puts("average"); else
       if (x*100>N) puts("hardcore"); else puts("pro");
  }
  return 0;
}