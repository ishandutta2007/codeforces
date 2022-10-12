#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int a=-1e9,b=-1e9;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      a=max(a,v);
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
      int v;
      cin >> v;
      b=max(b,v);
    }
    if(a>b){cout << "Alice\nAlice\n";}
    else if(a<b){cout << "Bob\nBob\n";}
    else{cout << "Alice\nBob\n";}
  }
  return 0;
}