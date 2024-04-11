#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,k,ax,ay,bx,by,i,j,r,ri,cnt,cur,last,curx[100100],cury[100100];
vector<pair<int,pair<int,int> > > x,y;
bool was;
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=0; i<k; i++) {
    scanf("%d%d%d%d",&ax,&ay,&bx,&by);
	if (ax==bx) x.push_back(make_pair(ax,make_pair(min(ay,by),max(ay,by))));
	 else y.push_back(make_pair(ay,make_pair(min(ax,bx),max(ax,bx))));
  }
  sort(x.begin(),x.end());
  for (cnt=i=0; i<x.size(); i=j) {
    cnt++;
	last=x[i].second.second;
	cur=m-last+x[i].second.first;
    for (j=i+1; j<x.size(); j++) {
      if (x[j].first!=x[i].first) break;
	  cur-=max(0,x[j].second.second-max(last,x[j].second.first));
      last=max(last,x[j].second.second);
    }
	curx[j]=cur;
	r^=cur;
  }
  r^=((n-cnt-1)%2)*m;
  sort(y.begin(),y.end());
  for (cnt=i=0; i<y.size(); i=j) {
    cnt++;
	last=y[i].second.second;
	cur=n-last+y[i].second.first;
    for (j=i+1; j<y.size(); j++) {
      if (y[j].first!=y[i].first) break;
	  cur-=max(0,y[j].second.second-max(last,y[j].second.first));
      last=max(last,y[j].second.second);
    }
	cury[j]=cur;
	r^=cur;
  }
  r^=((m-cnt-1)%2)*n;
  if (r) {
    for (j=0, i=1; i<n; i++) {
	  k=j;
	  if (j<x.size() && x[j].first==i) {
	    for (; j<x.size(); j++) if (x[j].first!=i) break;
		cur=curx[j];
	  } else cur=m;
	  if (cur==m) {
	    if (was) {
		  if (j<x.size()) i=x[j].first-1; else break;
		}
		was=true;
	  }
	  last=r^cur; ri=0;
	  if (last<cur) {
	    for (j=k; j<x.size(); j++) {
		  if (x[j].first!=i || x[j].second.first>=last) break;
		  last+=max(0,x[j].second.second-max(ri,x[j].second.first));
		  ri=max(ri,x[j].second.second);
		}
		puts("FIRST");
		printf("%d %d %d %d\n",i,last,i,m);
		was=false;
	    break;
	  }
	}
	if (i>=n || was) {
	was=false;
	for (i=1, j=0; i<m; i++) {
	  k=j;
	  if (j<y.size() && y[j].first==i) {
	    for (; j<y.size(); j++) if (y[j].first!=i) break;
		cur=cury[j];
	  } else cur=n;
	  if (cur==n) {
	    if (was) {
		  if (j<y.size()) i=y[j].first-1; else break;
		}
		was=true;
	  }
	  last=r^cur; ri=0;
	  if (last<cur) {
	    for (j=k; j<y.size(); j++) {
		  if (y[j].first!=i || y[j].second.first>=last) break;
		  last+=max(0,y[j].second.second-max(ri,y[j].second.first));
		  ri=max(ri,y[j].second.second);
		}
		puts("FIRST");
		printf("%d %d %d %d\n",last,i,n,i);
		was=false;
	    break;
	  }
	}
	if (i>=m || was) puts("SECOND");
	}
  } else puts("SECOND");
  return 0;
}