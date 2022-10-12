#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    long long res=0;
    deque<pl> dq;
    for(long long i=n-1;i>=0;i--){
      while(!dq.empty() && i<dq.back().first){dq.pop_back();}
      pl cur={i-a[i]+1,i};
      while(!dq.empty()){
        pl fr=dq.front();
        if(cur.first>fr.first){
          cur.second=fr.second;
          dq.pop_front();
        }
        else{break;}
      }
      dq.push_front(cur);
      res+=(dq.back().second-i+1);
      // cout << dq.back().first << " , " << dq.back().second << "\n";
      // cout << dq.back().second << " ";
    }
    cout << res << "\n";
  }
  return 0;
}