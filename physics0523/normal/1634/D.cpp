#include<bits/stdc++.h>

using namespace std;

int ask(int p,int q,int r){
  cout << "? " << p << ' ' << q << ' ' << r << '\n';
  fflush(stdout);
  int res;
  cin >> res;
  return res;
}

void ans(int x,int y){
  cout << "! " << x << ' ' << y << '\n';
  fflush(stdout);
  return;
}

int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    queue<int> qu;
    for(int i=1;i<=n;i++){qu.push(i);}
    while(qu.size()>=3){
      vector<int> od;
      set<int> st;
      for(int i=0;i<4;i++){
        if(qu.empty()){
          for(int j=1;j<=n;j++){
            if(st.find(j)==st.end()){
              od.push_back(j);
              break;
            }
          }
          break;
        }
        od.push_back(qu.front());
        st.insert(qu.front());
        qu.pop();
      }
      vector<pair<int,int>> vp;
      vp.push_back({ask(od[1],od[2],od[3]),0});
      vp.push_back({ask(od[0],od[2],od[3]),1});
      vp.push_back({ask(od[0],od[1],od[3]),2});
      vp.push_back({ask(od[0],od[1],od[2]),3});
      sort(vp.begin(),vp.end());
      qu.push(od[vp[0].second]);
      qu.push(od[vp[1].second]);
    }
    int x=qu.front();qu.pop();
    int y=qu.front();qu.pop();
    ans(x,y);
  }
  return 0;
}