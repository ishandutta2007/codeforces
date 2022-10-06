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
  array<Node *, 40> ch;
  int cnt;
  int orig;
  Node () {
    cnt = 0;
    ch = array<Node*, 40>();
  }
};

int N;
int Q;
char buf[114514];
string strs[114514];
Node *root;

int Rev(char c) {
  if ('a' <= c && c <= 'z') return 1 + c - 'a';
  else if ('0' <= c && c <= '9') return 28 + c - '0';
  else if (c == '.') return 0;
  assert(0);
}

void Register(string &str, int orig) {
  auto node = root;
  for (char c : str) {
    if (!node->ch[Rev(c)]) {
      node->ch[Rev(c)] = new Node();
    }
    node = node->ch[Rev(c)];
  }
  assert(!str.empty());
  assert(node);
  node->cnt++;
  node->orig = orig;
}

pair<int, string> Find(string &str) {
  auto node = root;
  for (char c : str) {
    if (!node->ch[Rev(c)]) return pair<int,string>(0, "-");
    node = node->ch[Rev(c)];
  }
  return make_pair(node->cnt, strs[node->orig]);
}

int main() {
  scanf("%d", &N);
  root = new Node();
  rep(i, N) {
    scanf("%s", buf);
    int m = strlen(buf);
    string str = buf;
    vector<string> ss;
    rep(j, m) {
      reps(k, j+1, m+1) {
        int l = k - j;
        ss.pb(str.substr(j, l));
      }
    }
    sort(all(ss));
    ss.erase(unique(all(ss)), ss.end());
    
    for (auto &s : ss) {
      Register(s, i);
    }
    strs[i] = str;
  }

  scanf("%d", &Q);
  rep(i, Q) {
    scanf("%s", buf);
    string str = buf;
    auto p = Find(str);
    printf("%d %s\n", p.first, p.second.c_str());   
  }
}