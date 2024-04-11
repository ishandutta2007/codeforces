#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int i,j,k,p,n,b[277];
char s[1010],t[1010];
bool a[1010];
vector <int> r;
int main() {
  scanf("%s",&s); n=strlen(s);
  r.push_back(0);
  for (i=0; i<n; i++) {
    b[s[i]]++;
    if (b[s[i]]>b[k]) k=s[i];
  }
  for (i=2; i<=n; i++) if (!a[i]) {
    if (i+i<=n) for (j=i+i; j<=n; j+=i) a[j]=true; else r.push_back(i-1);
  }
  if (n-r.size()>b[k]) { puts("NO"); return 0; } else puts("YES");
  for (i=p=0; i<r.size(); i++) {
    if (p!=k) while ((p<277 && b[p]==0) || p==k) p++;
    if (p>=277) p=k;
    b[p]--;
    t[r[i]]=p;
  }
  for (i=0; i<n; i++) if (t[i]==0) t[i]=k;
  puts(t);
  return 0;
}