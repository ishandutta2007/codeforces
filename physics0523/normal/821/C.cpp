#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int res=0,tg=1;
  set<int> free;
  stack<int> st;
  for(int i=0;i<2*n;i++){
    string s;
    cin >> s;
    if(s[0]=='a'){
      int v;
      cin >> v;
      st.push(v);
    }
    else{
      if(!st.empty() && st.top()==tg){st.pop();}
      else if(st.empty() && free.find(tg) != free.end()){
        free.erase(tg);
      }
      else{
        res++;
        while(!st.empty()){
          free.insert(st.top());
          st.pop();
        }
        free.erase(tg);
      }
      tg++;
    }
  }
  cout << res << '\n';
  return 0;
}