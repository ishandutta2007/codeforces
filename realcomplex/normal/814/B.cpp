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

const int N = 1005;
int a[N];
int b[N];
int n;

bool correct(int p[], int ix, int c){
  p[ix] = c;
  int cnt[N];
  for(int i = 0;i<N;i++)cnt[i] = 0;
  for(int i = 1;i<=n;i++){
    cnt[p[i]]++;
  }
  for(int i = 1;i<=n;i++){
    if(cnt[i] != 1)
      return false;
  }
  return true;
}

int main(){
  fastIO;
  cin >> n;
  vector<int>ix;
  for(int i = 1;i<=n;i++)cin >> a[i];
  for(int i = 1;i<=n;i++)cin >> b[i];
  for(int i = 1;i<=n;i++){
    if(a[i] != b[i]){
      ix.push_back(i);
    }
  }
  
  // ix size is in range [1,2]
  if(ix.size() == 1){
    set<int>is;
    for(int i = 1;i<=n;i++){
      is.insert(a[i]);
      is.insert(b[i]);
    }
    for(int i = 1;i<=n;i++){
      if(!is.count(i)){
        a[ix[0]] = i;
        for(int i = 1;i<=n;i++)cout << a[i] << " ";
        cout << "\n";
        return 0;
      }
    }
  }
  else{
    int cur[N];
    for(int i = 1;i<=n;i++)
      cur[i] = a[i];
    if(correct(cur,ix[0],b[ix[0]])){
      cur[ix[0]] = b[ix[0]];
      for(int i = 1;i<=n;i++)
        cout << cur[i] << " ";
      return 0;
    }
    for(int i = 1;i<=n;i++)
      cur[i] = a[i];
    cur[ix[1]] = b[ix[1]];
    for(int i = 1;i<=n;i++)cout << cur[i] << " ";
  }
  return 0;
}