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

    long long res=0;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
      int bef,aft;

      if(s[i]=='L'){bef=i;}
      else{bef=n-i-1;}

      aft=max(i,n-i-1);

      res+=bef;
      pq.push(aft-bef);
    }
    for(int i=0;i<n;i++){
      if(i){cout << " ";}
      res+=pq.top();pq.pop();
      cout << res;
    }cout << "\n";
  }
  return 0;
}