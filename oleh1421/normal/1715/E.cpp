//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> line;
#define endl '\n'
const int N = 1500010;
const ll mod=998244353;
const ll inf=1e18;
vector<pair<int,int> >g[N];
ll d[N];
ll x[N],y[N];
template <typename T, bool IS_MINIMIZED = true>
struct ConvexHullTrick {
  ConvexHullTrick() = default;

  void add(T a, T b) {
    if (!IS_MINIMIZED) {
      a = -a;
      b = -b;
    }
    const Line line(a, b);
    if (deq.empty()) {
      deq.emplace_back(line);
    } else if (deq.back().first >= a) {
      if (deq.back().first == a) {
        if (b >= deq.back().second) return;
        deq.pop_back();
      }
      for (int i = static_cast<int>(deq.size()) - 2; i >= 0; --i) {
        if (!must_pop(deq[i], deq[i + 1], line)) break;
        deq.pop_back();
      }
      deq.emplace_back(line);
    } else {
      if (deq.front().first == a) {
        if (b >= deq.front().second) return;
        deq.pop_front();
      }
      while (deq.size() >= 2 && must_pop(line, deq.front(), deq[1])) {
        deq.pop_front();
      }
      deq.emplace_front(line);
    }
  }

  T query(const T x) const {
    // assert(!deq.empty());
    int lb = -1, ub = deq.size() - 1;
    while (ub - lb > 1) {
      const int mid = (lb + ub) >> 1;
      (f(deq[mid], x) < f(deq[mid + 1], x) ? ub : lb) = mid;
    }
    return IS_MINIMIZED ? f(deq[ub], x) : -f(deq[ub], x);
  }

  T monotonically_increasing_query(const T x) {
    while (deq.size() >= 2 && f(deq.front(), x) >= f(deq[1], x)) {
      deq.pop_front();
    }
    return IS_MINIMIZED ? f(deq.front(), x) : -f(deq.front(), x);
  }

  T monotonically_decreasing_query(const T x) {
    for (int i = static_cast<int>(deq.size()) - 2; i >= 0; --i) {
      if (f(deq[i], x) > f(deq[i + 1], x)) break;
      deq.pop_back();
    }
    return IS_MINIMIZED ? f(deq.back(), x) : -f(deq.back(), x);
  }

 private:
  using Line = std::pair<T, T>;

  std::deque<Line> deq;

  using Real = long double;
  bool must_pop(const Line& l1, const Line& l2, const Line& l3) const {
    const Real lhs =
        static_cast<Real>(l3.second - l2.second) / (l2.first - l3.first);
    const Real rhs =
        static_cast<Real>(l2.second - l1.second) / (l1.first - l2.first);
    return lhs <= rhs;
    // const T lhs_num = l3.second - l2.second, lhs_den = l2.first - l3.first;
    // const T rhs_num = l2.second - l1.second, rhs_den = l1.first - l2.first;
    // return lhs_num * rhs_den <= rhs_num * lhs_den;
  }

  T f(const Line& l, const T x) const { return l.first * x + l.second; }
};
ConvexHullTrick<ll,true> CHT;
void solve(){
    int n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    for (int i=1;i<=n;i++) d[i]=inf;
    d[1]=0;
    for (int it=0;it<k;it++){
        set<pair<ll,int> >st;
        for (int i=1;i<=n;i++) st.insert({d[i],i});
        while (!st.empty()){
            int v=(*st.begin()).second;
            st.erase(st.begin());
            for (auto [to,w]:g[v]){
                if (d[to]>d[v]+w){
                    st.erase({d[to],to});
                    d[to]=d[v]+w;
                    st.insert({d[to],to});
                }
            }
        }
//        cout<<"X ";
//        for (int i=1;i<=n;i++) cout<<d[i]<<" ";
//        cout<<endl;
        ConvexHullTrick<ll,true> CHT;
        for (int i=1;i<=n;i++) x[i]=d[i];
        for (ll i=1;i<=n;i++){
            CHT.add(-2*i,i*i+d[i]);
        }
        for (ll i=1;i<=n;i++) d[i]=min(d[i],i*i+CHT.monotonically_increasing_query(i));
//        for (int i=1;i<=n;i++) cout<<d[i]<<" ";
//        cout<<endl;

    }
    set<pair<ll,int> >st;
    for (int i=1;i<=n;i++) st.insert({d[i],i});
    while (!st.empty()){
        int v=(*st.begin()).second;
        st.erase(st.begin());
        for (auto [to,w]:g[v]){
            if (d[to]>d[v]+w){
                st.erase({d[to],to});
                d[to]=d[v]+w;
                st.insert({d[to],to});
            }
        }
    }
    for (int i=1;i<=n;i++) cout<<d[i]<<" ";
    cout<<endl;




}
int main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt=1;

    while (tt--){
        solve();
    }
    return 0;
}
/**
1
8 86

**/