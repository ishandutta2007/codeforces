#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    string s;
    for(int i=0;i<m;i++){
      s.push_back('B');
    }
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      v--;
      v=min(v,m-1-v);
      if(s[v]=='B'){s[v]='A';}
      else{s[m-1-v]='A';}
    }
    cout << s << "\n";
  }
  return 0;
}