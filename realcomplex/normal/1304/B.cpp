#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

map<string,int> pos;
int rv[105];
int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  vector<string> t(n);
  for(int i = 0 ; i < n; i ++ ){
    cin >> t[i];
    pos[t[i]]=i;
  }
  string s;
  string mid = "";
  for(int i = 0 ; i < n ; i ++ ){
    rv[i]=-1;
    s = t[i];
    reverse(s.begin(), s.end());
    if(pos.count(s)){
      rv[i]=pos[s];
    }
    if(i==rv[i]){
      mid = t[i];
    }
  }
  for(int i = 0 ; i < n ; i ++ ){
    if(rv[i] > i){
      mid = t[i] + mid;
      s = t[i];
      reverse(s.begin(), s.end());
      mid = mid + s;
    }
  }
  cout << mid.size() << "\n" << mid << "\n";
  return 0;
}