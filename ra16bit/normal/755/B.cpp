#include <cstdio>
#include <string>
#include <set>
using namespace std;
int n,m,i,c;
set<string> a;
string s;
char st[555];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%s",st); s=st;
    a.insert(s);
  }
  for (i=0; i<m; i++) {
    scanf("%s",st); s=st;
    if (a.count(s)) c++;
  }
  if (m==c) {
    puts((n==c && c%2==0)?"NO":"YES");
    return 0;
  }
  n-=c;
  m-=c;
  if (c&1) m--;
  puts(n>m?"YES":"NO");
  return 0;
}