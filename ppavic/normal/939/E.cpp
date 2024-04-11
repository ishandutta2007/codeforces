#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
#include <iomanip>

using namespace std;

typedef long long ll;

ll qu;

multiset < ll > s,v;

ll x,y,sum,cnt = 0;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> qu;
  for(ll i = 0;i<qu;i++){
    cin >> x;
    if(x == 1){
      cin >> y;
      if(!s.empty() && (double)(sum + y + *s.rbegin()) / (double)(cnt + 2) < (double)(sum + *s.rbegin()) / (double)(cnt + 1)){
        v.insert(y);
        sum += y;cnt++;
      }
      else if(!v.empty() && y  < *v.rbegin()){
        s.insert(*v.rbegin());
        sum -= *v.rbegin();
        sum += y;
        v.erase(v.lower_bound(*v.rbegin()));
        v.insert(y);
      }
      else{
        s.insert(y);
        while(!s.empty() && (double)(sum + *s.begin() + *s.rbegin()) / (double)(cnt + 2) < (double)(sum + *s.rbegin()) / (double)(cnt + 1)){
          sum += *s.begin();cnt++;
          v.insert(*s.begin());
          s.erase(s.begin());
        }
      }
    }
    else{
      cout << fixed << setprecision(10) << (double)*s.rbegin() - (double)(sum + *s.rbegin()) / (double)(cnt + 1) << "\n";
    }
  }
}