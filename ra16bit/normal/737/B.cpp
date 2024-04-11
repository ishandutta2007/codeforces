#include <cstdio>
#include <vector>
using namespace std;
int n,a,b,k,p,i,j,m;
char s[200200];
vector<int> v;
int main() {
  scanf("%d%d%d%d",&n,&a,&b,&k);
  scanf("%s",s);
  s[n]='1';
  for (p=i=0; i<=n; i++) if (s[i]=='1') {
    for (j=p+b-1; j<i; j+=b) v.push_back(j+1);
    p=i+1;
  }
  m=v.size();
  m-=a-1;
  printf("%d\n",m);
  for (i=0; i<m; i++) printf("%d%c",v[i],(i+1==m)?'\n':' ');
  return 0;
}