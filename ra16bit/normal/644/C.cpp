#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
int n,i,pos,r;
string cur;
char st[55];
map<string,set<string>> m;
map<vector<string>,vector<string>> s;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",st); cur=st;
    cur=cur.substr(7);
    pos=cur.find('/');
    if (pos==-1) m[cur].insert(""); else
      m[cur.substr(0,pos)].insert(cur.substr(pos));
  }
  for (auto it=m.begin(); it!=m.end(); it++) {
    vector<string> v;
    for (auto jt=it->second.begin(); jt!=it->second.end(); jt++) v.push_back(*jt);
    s[v].push_back(it->first);
  }
  for (auto it=s.begin(); it!=s.end(); it++) if (it->second.size()>1) r++;
  printf("%d\n",r);
  for (auto it=s.begin(); it!=s.end(); it++) if (it->second.size()>1) {
    for (auto jt=it->second.begin(); jt!=it->second.end(); jt++) printf("http://%s ",jt->c_str());
    puts("");
  }
  return 0;
}