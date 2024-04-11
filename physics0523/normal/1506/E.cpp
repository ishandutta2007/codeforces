#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i=0;i<n;i++){cin >> p[i];}
    vector<int> sm,lg;
    priority_queue<int,vector<int>,greater<int>> spq;
    priority_queue<int> lpq;

    int ns=1;
    for(int i=0;i<n;i++){
      if(i==0 || p[i-1]!=p[i]){
        sm.push_back(p[i]);
        lg.push_back(p[i]);
        for(int j=ns;j<p[i];j++){
          spq.push(j);
          lpq.push(j);
        }
        ns=p[i]+1;
      }
      else{
        int od=spq.top();spq.pop();
        sm.push_back(od);

        od=lpq.top();lpq.pop();
        lg.push_back(od);
      }
    }

    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << sm[i];
    }cout << '\n';
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << lg[i];
    }cout << '\n';
  }
  return 0;
}