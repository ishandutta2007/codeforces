#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

int main(){
  fastIO;
  int n;
  cin >> n;
  vector<int> st;
  vector<int> ed;
  int l[n], r[n];
  for(int i = 0;i < n;i ++ ){
    cin >> l[i] >> r[i];
    st.push_back(l[i]);
    ed.push_back(r[i]);
  }
  sort(st.begin(), st.end());
  reverse(st.begin(), st.end());
  sort(ed.begin(), ed.end());
  int sum;
  int ans = 0;
  for(int i = 0;i < n;i ++ ){
    sum = 0;
    if(st[0] == l[i]){
      sum -= st[1];
    }
    else{
      sum -= st[0];
    }
    if(ed[0] == r[i]){
      sum += ed[1];
    }
    else{
      sum += ed[0];
    }
    ans = max(ans, sum);
  }
  cout << ans;
  return 0;
}