#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()

int main(){
  fastIO;
  int n;
  cin >> n;
  vector<pii> dble, single;
  int ww;
  for(int i = 0;i < n;i ++ ){
    cin >> ww;
    dble.push_back(mp(ww, i));
  }
  sort(dble.begin(), dble.end());
  char cc;
  int t;
  int p = 0;
  for(int i = 0;i < n*2; i ++ ){
    cin >> cc;
    if(cc == '0'){
      cout << dble[p].se + 1 << " ";
      single.push_back(mp(dble[p].fi, dble[p].se));
      p++; 
    }
    else{
      cout << single.back().se+1 << " ";
      single.pop_back();
    }
  }
  return 0; 
}