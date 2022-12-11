#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 9;
int m[N];
ll lf[N];
ll rf[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> m[i];
  }
  ll cur = 0;
  vector<pii> st;
  int las;
  for(int i = 0 ; i < n ; i ++ ){
    las = i;
    while(!st.empty() && st.back().fi >= m[i]){
      cur -= (st.back().fi - m[i]) * 1ll * (las - st.back().se);
      las = st.back().se;
      st.pop_back();
    }
    cur += m[i];
    lf[i] = cur;
    st.push_back(mp(m[i], las));
  }
  st.clear();
  for(int i = n - 1; i >= 0 ; i -- ){
    las = i;
    while(!st.empty() && st.back().fi >= m[i]){
      cur -= (st.back().fi - m[i]) * 1ll * (st.back().se - las);
      las = st.back().se;
      st.pop_back();
    }
    cur += m[i];
    rf[i] = cur;
    st.push_back(mp(m[i], las));
  }
  ll bes = 0;
  int idx = -1;
  for(int i = 0 ; i < n; i ++ ){
    if(lf[i] + rf[i] - m[i] > bes){
      bes = lf[i] + rf[i] - m[i];
      idx = i;
    }
  }
  for(int i = idx - 1; i >= 0 ; i -- )
    m[i] = min(m[i], m[i+1]);
  for(int i = idx + 1; i < n; i ++ )
    m[i] = min(m[i], m[i-1]);
  for(int i = 0 ; i < n ; i ++ )
    cout << m[i] << " ";
  return 0;
}