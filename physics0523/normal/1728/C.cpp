#include<bits/stdc++.h>

using namespace std;

int f(int x){
  string s=to_string(x);
  return s.size();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,res=0;
    cin >> n;

    priority_queue<int> a,b;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      a.push(v);
    }
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      b.push(v);
    }

    while(!a.empty()){
      int ad=a.top();a.pop();
      int bd=b.top();b.pop();
      if(ad==bd){continue;}

      if(ad<bd){bd=f(bd);}
      else{ad=f(ad);}
      a.push(ad);
      b.push(bd);
      res++;
    }
    cout << res << "\n";
  }
  return 0;
}