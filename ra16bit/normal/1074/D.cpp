#include <bits/stdc++.h>
using namespace std;
int q,t,l,r,x,wl,wr,ans,lst;
vector<set<pair<int,int>>> s;
map<int,int> w;
bool ok;
void ins(int wl, int l, int r, int x) {
//printf("%d : [%d %d] %d\n",wl,l,r,x);
  if (l>=r) return;
  auto lt=s[wl].lower_bound({l,0});
  auto rt=s[wl].lower_bound({r,0});
  if (lt->first==l) {
    w[r]=wl;
	s[wl].insert({r,(lt->second)^x});
  } else {
	w[l]=wl;
	s[wl].insert({l,(rt->second)^x});
  }
}
int main() {
  scanf("%d",&q);
  while (q--) {
    scanf("%d%d%d",&t,&l,&r);
	l^=lst;
	r^=lst;
	if (l>r) swap(l,r);
	r++;
/*	for (auto& ss : s) {
	for (auto it=ss.begin(); it!=ss.end(); it++) printf("(%d %d), ",it->first,it->second);
	puts("");
	}
	puts("____");*/
	if (w.count(l)) wl=w[l]; else wl=-1;
	if (w.count(r)) wr=w[r]; else wr=-1;
	if (wl==wr && wl!=-1) {
	  ok=true;
	  auto lt=s[wl].lower_bound({l,0});
	  auto rt=s[wl].lower_bound({r,0});
	  ans=(lt->second)^(rt->second);
	} else ok=false;
	if (t==1) {
	  scanf("%d",&x);
	  x^=lst;
	  if (ok) continue;
	  if (wl==-1 && wr==-1) {
	    w[l]=s.size();
		w[r]=s.size();
	    s.push_back({{l,0},{r,x}});
	  } else {
	    if (wl==-1) swap(wl,wr);
		if (wr!=-1 && s[wl].size()<s[wr].size()) swap(wl,wr);
		ins(wl,l,r,x);
		if (wr!=-1 && wr!=wl) {
		  auto lt=s[wr].lower_bound({l,0});
		  if (lt!=s[wr].end() && l==lt->first) {
		    auto rt=lt;
		    for (rt++; rt!=s[wr].end(); rt++) ins(wl,l,rt->first,(lt->second)^(rt->second));
			rt=lt;
		    while (rt!=s[wr].begin()) {
			  rt--;
			  ins(wl,rt->first,l,(lt->second)^(rt->second));
		    }
		  } else {
		    auto rt=lt=s[wr].lower_bound({r,0});
		    for (rt++; rt!=s[wr].end(); rt++) ins(wl,r,rt->first,(lt->second)^(rt->second));
			rt=lt;
		    while (rt!=s[wr].begin()) {
			  rt--;
			  ins(wl,rt->first,r,(lt->second)^(rt->second));
			}
		  }
		}
	  }
	} else if (ok) {
	  printf("%d\n",ans);
	  lst=ans;
	} else {
	  puts("-1");
	  lst=1;
	}
  }
  return 0;
}