#include <cstdio>
#include <vector>
using namespace std;
int n,i,j,k,x,y,v[5050];
vector <int> a,b;
char s[5050][5050];
bool u[5050];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",s[i]);
    for (j=0; j<n; j++) if (s[i][j]=='1') v[i]++;
  }
  for (i=1; i<=n; i++) if (u[v[i]]) {
    for (k=0; k<n; k++) if (v[k]!=-1 && i!=k) {
      if (s[i][k]=='0') a.push_back(k); else b.push_back(k);
    }
    for (k=0; k<b.size(); k++) {
      x=b[k];
      for (y=0; y<a.size(); y++) if (s[x][a[y]]=='1') {
        printf("%d %d %d\n",i+1,x+1,a[y]+1);
        return 0;
      }
    }
    puts("-1");
    return 0;
  } else u[v[i]]=true;
  puts("-1");
  return 0;
}