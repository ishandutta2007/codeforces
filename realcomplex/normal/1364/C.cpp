#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int n;
  cin >> n;
  vector<int> mx(n);
  for(int i = 0 ; i < n ; i ++ )
    cin >> mx[i];
  vector<int> sol(n);
  for(int i = 0 ; i < n; i ++ )
    sol[i] = -1;
  vector <int> emp;
  int cur = 0;
  int d;
  for(int i = 0 ; i < n; i ++ ){
    emp.push_back(i);
    while(mx[i] > cur){
      if(emp.empty()){
        cout << -1;
        return 0;
      }
      sol[emp.back()] = cur;
      cur ++ ;
      emp.pop_back();
    }
    
  }
  for(int i = 0 ; i < n; i ++ ){
    if(sol[i] == -1) sol[i] = (int)1e6;
    cout << sol[i] << " ";
  }
  return 0;
}