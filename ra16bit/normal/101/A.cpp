#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
int n,k,i,j,p,S,b[44];
pair <int, char> a[44];
char s[100100];
int main() {
  scanf("%s",s);
  n=strlen(s);
  scanf("%d",&k);
  for (i=0; i<26; i++) a[i].second='a'+i;
  for (i=0; i<n; i++) a[s[i]-'a'].first++;
  sort(a,a+26);
  for (p=-1,i=0; i<26; i++) {
    b[a[i].second-'a']=i;
    S+=a[i].first;
    if (S<=k) p=i;
  }
  printf("%d\n",25-p);
  for (i=0; i<n; i++) if (b[s[i]-'a']>p) putchar(s[i]);
  return 0;
}