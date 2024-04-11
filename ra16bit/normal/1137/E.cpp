#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pll;
const int MX=300300;
int m,tp,x,y;
long long X,Y,z;
set<pll> s,q;
set<pll>::iterator it,it2,qt;
pll cur;
map<long long, long long> o;
int main() {
  scanf("%d%d",&x,&m);
  s.insert({-x,0});
  while (m--) {
    scanf("%d%d",&tp,&x);
    if (tp==1) {
      z=s.begin()->first;
      s.clear();
      q.clear();
      s.insert({z-x,X=Y=0});
    } else if (tp==3) {
      scanf("%d",&y);
      X+=x;
      Y+=y;
      //if (!q.empty()) printf("%I64d vs %I64d\n",q.top().first,Y);
      while (!q.empty() && q.begin()->first<=Y) {
        it=s.upper_bound({q.begin()->second-1,1});
        it--;
        z=it->first;
        s.erase(it);
        it=s.upper_bound({q.begin()->second-1,1});
        cur={z,it->second};
        //printf("new %d %d\n",int(z),int(it->second));
        s.erase(it);
        s.insert(cur);
        q.erase(q.begin());
        qt=q.find({o[cur.first],cur.first});
        if (qt!=q.end()) q.erase(qt);
        it=s.lower_bound(cur);
        if (it!=s.begin()) {
          it2=it; it2++;
          if (it2==s.end()) z=0; else z=-it2->first;
          it--;
          long long P=it->second-cur.second;
          long long Q=z+cur.first;
          cur={(P%Q)?(P/Q+1):(P/Q),cur.first};
          o[cur.second]=cur.first;
          q.insert(cur);
        }
      }
    } else {
      it=s.begin();
      it2=it; it2++;
      if (it2==s.end()) z=0; else z=-it2->first;
      if (it->second+X+z*Y>0) {
        long long P=-X+it->first*Y-it->second;
        long long Q=z+it->first;
        //printf("push %I64d/%I64d %I64d\n",P,Q,it->first);
        cur={(P%Q)?(P/Q+1):(P/Q),it->first};
        o[cur.second]=cur.first;
        q.insert(cur);
        s.insert({it->first-x,-X+it->first*Y});
      } else {
        cur=*s.begin();
        s.erase(s.begin());
        cur.first-=x;
        s.insert(cur);
      }
    }
/*    for (it=s.begin(); it!=s.end(); it++) {
      it2=it; it2++;
      if (it2==s.end()) z=0; else z=-it2->first;
      printf("[%d %d %d] ",int(-it->first),int(it->second),int(it->second+X+z*Y));
    }
    puts("");*/
    it=s.begin();
    it2=it; it2++;
    if (it2==s.end()) z=0; else z=-it2->first;
    printf("%I64d %I64d\n",z+1,it->second+X+z*Y);
  }
  return 0;
}