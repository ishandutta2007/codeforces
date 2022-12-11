#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int N = (int)1e6 + 9;
int cnt[N];
ll sqr[N];

int BLOCK;

int bb[N];

struct Query{
  int left_bound;
  int right_bound;
  int index;
  bool operator< (Query B){
    if(bb[left_bound] == bb[B.left_bound]){
      return right_bound < B.right_bound;
    }
    return left_bound < B.left_bound;
  }
};


ll current;

void add(int ri){
  current -= 1ll * sqr[cnt[ri]] * ri;
  cnt[ri] ++ ;
  current += 1ll * sqr[cnt[ri]] * ri;
}

void rem(int ri){
  current -= 1ll * sqr[cnt[ri]] * ri;
  cnt[ri] -- ;
  current += 1ll * sqr[cnt[ri]] * ri;
}

int main(){
  
  int n, q;
  scanf("%i %i", &n, &q);
  for(ll i = 0;i < N;i ++ )
    sqr[i] = 1ll * i * i;
  BLOCK = int(sqrt(n));
  int a[n];
  for(int i = 0; i < n;i ++ ){
    scanf("%i", &a[i]);
  }
  for(int i = 0;i < N ; i ++ )
    bb[i] = i/BLOCK;
  Query st[q];
  ll answer[q];
  int l, r;
  for(int i = 0;i < q;i ++ ){
    scanf("%i %i", &l, &r);
    --l;
    --r;
    st[i].left_bound = l;
    st[i].right_bound = r;
    st[i].index = i;
  }
  sort(st, st + q);
  int cl = 0, cr = -1;
  int tl, tr;
  for(int j = 0 ;j < q;j ++ ){  
    tl = st[j].left_bound;
    tr = st[j].right_bound;
    while(cl < tl){
      rem(a[cl++]);
    }
    while(cl > tl){
      add(a[--cl]);
    }
    while(cr < tr){
      add(a[++cr]);
    }
    while(cr > tr){
      rem(a[cr--]);
    }
    answer[st[j].index] = current;
  }
  for(int j = 0;j < q;j ++ ){
    printf("%lld\n", answer[j]);
  }
  return 0;
}