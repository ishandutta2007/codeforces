#include <bits/stdc++.h>
using namespace std;
const int MX=200200,md=998244353;

struct Dist {
  int turns,steps,rl;

  Dist() : turns(0), steps(0), rl(0) {}
  Dist(int t, int s) : turns(t), steps(s) {
    rl=((1<<min(t,22))+s);
  }
} dst[MX][22],cur,nxtturn,nxtstep;
int n,m,i,x,y,best;
vector<int> g[MX],o[MX];

bool operator==(const Dist& a, const Dist& b) {
  return (a.turns==b.turns) && (a.steps==b.steps);
}

bool operator<(const Dist& a, const Dist& b) {
  if (a.turns==b.turns) return a.steps<b.steps;
  if (a.turns>20) {
    if (b.turns>20) return a.turns<b.turns;
    return false;
  }
  if (b.turns>20) return true;
  return a.rl<b.rl;
};

typedef pair<Dist,int> PDist;
priority_queue<PDist,vector<PDist>,greater<PDist>> q;

inline void upd(int j, int k, Dist& cur) {
  if (dst[j][k].steps==0 || cur<dst[j][k]) {
    dst[j][k]=cur;
    q.push({cur,((j<<5)+k)});
  }
}

long long pw2(int x) {
  if (x==0) return 1LL;
  if (x&1) return (pw2(x-1)*2)%md;
  long long z=pw2(x/2);
  return (z*z)%md;
}

int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    o[y].push_back(x);
  }
  dst[1][0]={0,1};
  q.push({dst[1][0],(1<<5)});
  best=-1;
  while (!q.empty()) {
    x=(q.top().second>>5);
    y=(q.top().second&31);
    cur=q.top().first;
    q.pop();
    if (!(cur==dst[x][y])) continue;
    //printf("%d %d = 2^%d + %d\n",x,y,cur.turns,cur.steps-1);
    if (x==n && (best==-1 || cur<dst[x][best])) best=y;
    nxtturn={cur.turns+1,cur.steps};
    nxtstep={cur.turns,cur.steps+1};
    if (y&1) {
      for (int j: o[x]) upd(j,y,nxtstep);
      upd(x,min(y+1,20),nxtturn);
    } else {
      for (int j: g[x]) upd(j,y,nxtstep);
      upd(x,min(y+1,21),nxtturn);
    }
  }
  printf("%d\n",int((pw2(dst[n][best].turns)+dst[n][best].steps+md-2)%md));
  return 0;
}