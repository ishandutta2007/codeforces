#include<bits/stdc++.h>
#define X first
#define Y second
#define pb emplace_back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for(int (X)=(0);(X)<(Y);++(X))
#define REP rep
#define rrep(X,Y) for(int (X)=(Y)-1;(X)>=0;++(X))
#define all(x) (x).begin(),(x).end()
#define eb pb

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
#define rreps(X,S,Y) for(int (X)=(Y)-1;(X)>=(S);--(X))

template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}

struct Node {
  LL l;
  LL r;
  array<Node *, 2> ch;
  int bits;
  Node (LL l, LL r, int bits) : l(l), r(r), ch(), bits(bits) {}
};

int N;
Node *root;
char buf[114514];

Node *Reg(LL wishl, LL wishr, Node *node, LL watchl, LL watchr, bool black) {
  if (wishr <= watchl || watchr <= wishl) return node;
  if (wishl <= watchl && watchr <= wishr) {
    assert(wishl == watchl && watchr == wishr);
    if (!node) node = new Node(wishl, wishr, 1 << black);
    node->bits |= (1 << black);
    if (node->bits == 3) {
      puts("-1");
      exit(0);
    }
    assert(node->bits == (1 << black));
    return node;
  }

  if (!node) node = new Node(watchl, watchr, 1 << black);
  node->bits |= 1 << black;
  
  LL mid = (watchl + watchr)/2;
  node->ch[0] = Reg(wishl, wishr, node->ch[0], watchl, mid, black);
  node->ch[1] = Reg(wishl, wishr, node->ch[1], mid, watchr, black);
  return node;
}

int Cnt(LL v) {
  int ret = 0;
  while (1) {
    v /= 2;
    if (v == 0) return ret;
    ret++;
  }
}

vector<string> ans;
void Dfs(Node *node) {
  if (!node) return;
  if (!(node->bits >> 1 & 1)) return;
  
  if (!(node->bits & 1)) {
    LL l = node->l;
    LL r = node->r;
    assert(node->bits >> 1);
    LL a = (l >> 24) & 255LL;
    LL b = (l >> 16) & 255LL;
    LL c = (l >> 8) & 255LL;
    LL d = (l) & 255LL;
    int m = Cnt(r - l);
    assert((1LL << m) == r - l);
    assert((((1LL << m)-1) & l) == 0);
    if (m > 0) {
      sprintf(buf, "%lld.%lld.%lld.%lld/%d", a, b, c, d, 32-m);
    } else {
      sprintf(buf, "%lld.%lld.%lld.%lld", a, b, c, d, 32-m);
    }
    ans.eb(buf);
    return;
  }

  Dfs(node->ch[0]);
  Dfs(node->ch[1]);
}

using Tup = tuple<int, LL, bool>;
vector<Tup> ts;

int main(){
  scanf("%d", &N);
  root = new Node(0, 1LL << 32, 0);
  fgets(buf, sizeof(buf), stdin);
  rep(i, N) {
    buf[0] = '\0';
    fgets(buf, sizeof(buf), stdin);
    bool black = buf[0] == '-';
    LL a, b, c, d;
    int m = 0;
    if (strchr(buf, '/')) {
      int ret = sscanf(buf+1, "%lld.%lld.%lld.%lld/%d", &a, &b, &c, &d, &m);
      assert(ret == 5);
      m = 32 - m;
    } else {
      int ret = sscanf(buf+1, "%lld.%lld.%lld.%lld", &a, &b, &c, &d);
      assert(ret == 4);
    }
    LL l = (a << 24) + (b << 16) + (c << 8) + d;
    //printf("%llx %llx %llx\n", l, (((1LL << m)-1)), (((1LL << Cnt(l))-1) & l));
    assert((((1LL << m)-1) & l) == 0);
    ts.eb(Tup(m, l, black));
    //printf("%lld %lld %d\n", l, r, black);
  }
  sort(all(ts));
  for (auto &t : ts) {
    int m;
    LL l;
    bool black;
    tie(m, l, black) = t;
    LL r = l + (1LL << m);
    Reg(l, r, root, 0, 1LL << 32, black);
  }

  Dfs(root);
  printf("%d\n", (int)ans.size());
  for (auto &str : ans) {
    printf("%s\n", str.c_str());
  }
  return 0;
}