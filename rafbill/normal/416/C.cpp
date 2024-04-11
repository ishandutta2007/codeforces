#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <queue>
#include <functional>

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, j, k) for(long i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(long i = (j); i >= (k); --i)

using namespace std;

long C[1001];
long P[1001];
long R[1001];

long I[1001];
long J[1001];

struct PQC{
  bool operator()(long const& a, long const& b) const{
    if(P[I[a]] < P[I[b]]) return true;
    else if(P[I[a]] > P[I[b]]) return false;
    else return a < b;
  }
};

int main(int, char**){
  ios_base::sync_with_stdio(false);
  long n; cin >> n;
  FOR(i, n) cin >> C[i] >> P[i];
  long k; cin >> k;
  FOR(i, k) cin >> R[i];

  FOR(i, n) I[i] = i;
  FOR(i, k) J[i] = i;
  sort(I, I + n, [&](long const& a, long const& b) -> bool{
    return C[a] < C[b];
  });
  sort(J, J + k, [&](long const& a, long const& b) -> bool{
    return R[a] < R[b];
  });

  vector<pair<long, long>> RES;
  long pres = 0;
  long j = 0;
  priority_queue<long, vector<long>, PQC> pqueue;

  FOR(i, k){
    while(j != n && C[I[j]] <= R[J[i]]){
      pqueue.push(j);
      j += 1;
    }
    if(!pqueue.empty()){
      long m = pqueue.top();
      pqueue.pop();
      RES.push_back(make_pair(J[i]+1, I[m]+1));
      pres += P[I[m]];
    }
  }

  cout << RES.size() << " " << pres << "\n";
  for(auto const& p : RES){
    cout << p.second << " " << p.first << "\n";
  }
  cout << flush;

  return 0;
}