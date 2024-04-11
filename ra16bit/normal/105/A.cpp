#include <cstdio>
#include <string>
#include <map>
using namespace std;
int n,m,x,e;
double y;
map<string,int> a;
map<string,int>::iterator it;
string st;
char s[22];
int main() {
  scanf("%d%d%lf",&n,&m,&y);
  x=y*100+1e-5;
  while (n--) {
    scanf("%s",s); st=s;
    scanf("%d",&e); e*=x;
    if (e>=10000) a[st]=e/100;
  }
  while (m--) {
    scanf("%s",s); st=s;
    if (!a.count(st)) a[st]=0;
  }
  printf("%d\n",a.size());
  for (it=a.begin(); it!=a.end(); it++) printf("%s %d\n",it->first.c_str(),it->second);
  return 0;
}