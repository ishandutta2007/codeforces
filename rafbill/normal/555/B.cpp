#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <utility>

#define FOR(i, n) for(long long int i = 0; i < n; ++i)
#define FORU(i, j, k) for(long long int i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(long long int i = (j); i >= (k); --i)

using namespace std;

const long long int MOD = 1000000007;
#define X first
#define Y second

long long int L[200000];
long long int R[200000];

long long int ANS[200000];

int main(int, char**){
  std::ios::sync_with_stdio(false);
  long long int n, m; cin >> n >> m;
  FOR(i, n) cin >> L[i] >> R[i];
  vector<pair<long long int, pair<long long int, long long int>>> A;
  FOR(i, n-1){
    A.push_back(make_pair(L[i+1]-R[i], make_pair(R[i+1]-L[i], i)));
  }
  sort(A.begin(), A.end(), greater<pair<long long int, pair<long long int, long long int>>>());
  priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> Q;
  vector<pair<long long int, long long int>> B(m);
  FOR(i, m) cin >> B[i].X;
  FOR(i, m) B[i].Y = i;
  sort(B.begin(), B.end(), greater<pair<long long int, long long int>>());
  while(A.size() > 0 || !Q.empty()){
    if(B.empty()){
      cout << "No" << endl;
      return 0;
    }
    if(A.size() > 0 && B.size() > 0 && A.back().X <= B.back().X){
      Q.push(A.back().Y);
      A.pop_back();
    }else{
      if(!Q.empty()){
        auto p = Q.top();
        if(p.X >= B.back().X){
          ANS[p.Y] = B.back().Y;
          Q.pop();
        }else{
        }
      }
      B.pop_back();
    }
  }
  cout << "Yes" << endl;
  FOR(i, n-1) cout << ANS[i]+1 << " "; cout << endl;
  return 0;
}