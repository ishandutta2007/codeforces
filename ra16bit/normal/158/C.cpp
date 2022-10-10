#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;
int i,j,n,m,l,cur,p[2020];
char s[222];
string st,c[2020];
vector <int> v;
pair <int, string> pr;
map <pair <int, string>, int> mp;
int main() {
  scanf("%d",&n); p[0]=-1;
  for (i=0; i<n; i++) {
    scanf("%s",s);
    if (s[0]=='p') {
      v.clear();
      for (j=cur; j>=0; j=p[j]) v.push_back(j);
      for (j=int(v.size())-1; j>=0; j--) printf("%s/",c[v[j]].c_str());
      puts("");
    } else {
      scanf("%s",s);
      l=strlen(s);
      if (s[l-1]!='/') s[l++]='/';
      st="";
      for (j=0; j<l; j++) if (s[j]=='/') {
        if (st=="..") cur=p[cur]; else if (st!="") {
          pr=make_pair(cur,st);
          if (mp.count(pr)==0) {
            mp[pr]=++m;
            c[m]=st;
            p[m]=cur;
            cur=m;
          } else cur=mp[pr];
        } else cur=0;
        st="";
      } else st+=s[j];
    }
  }
  return 0;
}