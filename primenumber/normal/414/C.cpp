#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cstdint>
#include <cmath>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define EACH(i,x)   for(auto & i : x)
#define ALL(x)      begin(x),end(x)

using namespace std;

typedef vector<int> vecint;

vector<vecint> tree(4194304);
vector<int64_t> inv(4194304);
vector<int64_t> inv2(4194304);
void make_tree(int i,int begin_i,int end_i,const vecint& a){
  tree[i].assign(a.begin()+begin_i,a.begin()+end_i);
  if(end_i-begin_i>=2){
    int mid = (begin_i+end_i)/2;
    make_tree(i*2,begin_i,mid,a);
    make_tree(i*2+1,mid,end_i,a);
    for(int c:tree[i*2]){
      auto itr=lower_bound(ALL(tree[i*2+1]),c);
      auto itr2=upper_bound(ALL(tree[i*2+1]),c);
      inv[i]+=itr-tree[i*2+1].begin();
      inv2[i]+=tree[i*2+1].end()-itr2;
    }
    sort(ALL(tree[i]));
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  int l=1<<n;
  vecint a(l);
  REP(i,l){
    scanf("%d",&a[i]);
  }
  make_tree(1,0,l,a);
  vector<int64_t> invs(n+1);
  vector<int64_t> invs2(n+1);
  REP(i,n){
    FOR(j,1<<i,1<<(i+1)){
      invs[i+1]+=inv[j];
      invs2[i+1]+=inv2[j];
    }
  }
  int m;
  scanf("%d",&m);
  REP(i,m){
    int q;
    scanf("%d",&q);
    FOR(j,1,q+1){
      swap(invs[n-j+1],invs2[n-j+1]);
    }
    int64_t sum = 0;
    REP(j,n+1){
      sum+=invs[j];
    }
    printf("%I64d\n",sum);
  }
  return 0;
}