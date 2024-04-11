#include<bits/stdc++.h>
#define X first
#define Y second
#define pb emplace_back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for(int (X) = 0;(X) < (Y);++(X))
#define REP rep
#define rrep(X,Y) for( int (X) =(Y)-1;(X) >= 0;--(X))
#define all(X) (X).begin(),(X).end()
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef ll LL;
typedef pii PII;
typedef pll PLL;
const ll MOD=1e9+7;

#define rall(X) (X).rbegin(),(X).rend()
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define reps(X,S,Y) for(int (X)=S;(X)<(Y);++(X))
#define rreps(X,S,Y) for(int (X) =(Y)-1; (X)>=(S);--(X))
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}

const LL INF = 0x3fffffffffff;

struct Node {
  LL c;
  LL k;
  Node () {
    c = 0;
    k = -INF;
  }

  Node(LL d) {
    c = d;
    k = 0;
  }
};

int mysize;
vector<Node> seg;

Node Merge(Node f1, Node f2) {
  Node ret;
  ret.c = f1.c + f2.c;
  ret.k = max(f1.k + f2.c, f2.k);
  return ret;
}

void Update(int k, Node n) {
  k += mysize-1;
  seg[k] = n;
  while (k > 0) {
    k = (k-1)/2;
    seg[k] = Merge(seg[k*2+1], seg[k*2+2]);
  }
}

Node Get(int wishl, int wishr, int k, int watchl, int watchr) {
  int mid;
  Node lval, rval;

  if (wishr <= watchl || watchr <= wishl) return Node();
  if (wishl <= watchl && watchr <= wishr) return seg[k];

  mid = (watchl+watchr)/2;
  lval = Get(wishl, wishr, k*2+1, watchl, mid);
  rval = Get(wishl, wishr, k*2+2, mid, watchr);
  return Merge(lval, rval);
}

int Q;
char cmd[314514];
int T[314514];
int S[314514];
int I[314514];
LL D[314514];
LL Y[1145141];
//vector<int> ts;

int main(){
  scanf("%d", &Q);
  rep(i, Q) {
    scanf(" %c", &cmd[i]);
    if (cmd[i] == '+') {
      scanf("%d%lld", &T[i], &D[i]);
      //ts.eb(T[i]);
    } else if (cmd[i] == '-') {
      scanf("%d", &I[i]);
      --I[i];
    } else if (cmd[i] == '?') {
      scanf("%d", &S[i]);
      //ts.eb(S[i]);
    } else assert(0);
  }
  //sort(all(ts));
  //ts.erase(unique(all(ts)), ts.end());

  int N = 1e6 + 1;//ts.mysize();
  mysize = 1;
  while (mysize < N) mysize *= 2;
  
  seg.resize(mysize*2, Node(-1));
  rrep(k, mysize-1) {
    seg[k] = Merge(seg[k*2+1], seg[k*2+2]);
  }

  Update(0, Node());
  rep(i, Q) {
    if (cmd[i] == '+') {
      //auto itr = lower_bound(all(ts), T[i]);
      //assert(itr != ts.end());
      //Update(itr - ts.begin(), D[i]);
      Update(T[i], Node(D[i]-1));
      Y[T[i]] = D[i];
    } else if (cmd[i] == '-') {
      int t = T[I[i]];
      Y[t] = 0;
      //auto itr = lower_bound(all(ts), t);
      //assert(itr != ts.end());
      //Update(itr - ts.begin(), -1);
      Update(t, Node(-1));
    } else if (cmd[i] == '?') {
      //auto itr = lower_bound(all(ts), S[i]);
      //assert(itr != ts.end());
      //printf("idx: %d\n", itr - ts.begin());
      //auto node = Get(0, itr - ts.begin() + 1, 0, 0, mysize);
      auto node = Get(0, S[i], 0, 0, mysize);
      //printf("c,k: %lld %lld\n", node.c, node.k);
      printf("%lld\n", max(node.c, node.k) + Y[S[i]]);
    } else assert(0);

    //rep(i, N) {
    //  printf("%d      ", ts[i]);
    //}puts("");
    /*auto node = Node();
    rep(i, 8) {
      auto d = seg[mysize-1+i];
      node = Merge(node, seg[mysize-1+i]);
      printf("(%lld, %lld)  ", node.c, node.k);
    }puts("");*/
  }
}