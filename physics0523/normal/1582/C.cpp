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
    string s;
    cin >> s;
    int res=1e9+7;
    for(char c='a';c<='z';c++){
      deque<char> dq;
      for(auto &nx : s){dq.push_back(nx);}
      int cr=0;
      while(dq.size()>=2){
        if(dq.front()==dq.back()){
          dq.pop_front();
          dq.pop_back();
        }
        else if(dq.front()==c){
          cr++;
          dq.pop_front();
        }
        else if(dq.back()==c){
          cr++;
          dq.pop_back();
        }
        else{
          cr=1e9+7;break;
        }
      }
      res=min(res,cr);
    }
    if(res>1e9){res=-1;}
    cout << res << '\n';
  }
  return 0;
}