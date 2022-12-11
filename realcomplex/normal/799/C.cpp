#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = (int)1e5 + 9;
int maxB[N];

int search(vector<pii> cur, int t){
  sort(cur.begin(),cur.end());
  for(int i = 0;i<N;i++)
    maxB[i] = 0;
  vector<int>R[N];
  int p = 1;
  int l , r , mid;
  int ans = 0;
  for(int i = 0;i < len(cur); i ++ ){
    l = -1 ,r = p+1;
    while( r - l > 1){
      mid = (l + r) / 2;
      if(cur[mid].fi >= cur[i].fi){
        r = mid;
      }
      else if(cur[mid].fi + cur[i].fi > t){
        r = mid;
      }
      else{
        l = mid;
      }
    }
    if(i >= 1)
      if(cur[i].fi + cur[i-1].fi <= t)
        ans = max(ans,cur[i].se + maxB[i-1]);
    ++l;
    if(l != 0){
      if(maxB[l] != 0)
        ans = max(ans,maxB[l] + cur[i].se);
    }
    R[cur[i].fi].push_back(cur[i].se);
    maxB[p] = max(maxB[p-1],cur[i].se);
    ++p;
  }
  int sz;
  for(int i = 0;i < N;i ++ ){
    sort(R[i].begin(), R[i].end());
    sz = R[i].size();
    if(sz <= 1)
      continue;
    if( i * 2 > t)
      continue;
    ans = max(ans,R[i][sz-1] + R[i][sz - 2]);
  }
  return ans;
}

int main(){
  fastIO;
  int n;
  int c,d;
  cin >> n >> c >> d;
  vector<pii> C, D;
  int bi,ci;
  char typ;
  int mc = 0, md = 0;
  for(int i = 0;i<n;i++){
    cin >> bi >> ci >> typ;
    if(typ == 'C'){
      if(ci <= c)
        mc = max(mc,bi);
      C.push_back(mp(ci,bi));
    }
    else{
      if(ci <= d)
        md = max(md,bi);
      D.push_back(mp(ci,bi));
    }
  }
  int ans = 0;
  if(mc != 0 and md != 0)
    ans = mc+md;
  
  cout << max(ans, max(search(C,c), search(D,d)));
  return 0;
}