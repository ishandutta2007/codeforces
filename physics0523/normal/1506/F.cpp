#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<pi> p(n);
    for(int i=0;i<n;i++){cin >> p[i].first;}
    for(int i=0;i<n;i++){cin >> p[i].second;}
    p.push_back(make_pair(1,1));
    sort(p.begin(),p.end());
    int res=0;
    for(int i=0;i<n;i++){
      int df=p[i].first-p[i].second;
      int ds=p[i+1].first-p[i+1].second;
      if(df==ds){
        if(df%2==0){
          res+=(p[i+1].first-p[i].first);
        }
      }
      else{
        res+=((ds/2)-(df/2));
      }
      //cerr << i << ':' << df << ',' << ds << ' ' << res << '\n';
    }
    cout << res << '\n';
  }
  return 0;
}