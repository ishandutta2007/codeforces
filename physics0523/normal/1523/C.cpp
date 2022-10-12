#include<bits/stdc++.h>

using namespace std;

void output(vector<int> v){
  for(int i=0;i<v.size();i++){
    if(i){cout << '.';}
    cout << v[i];
  }cout << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> res;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      if(i==0){res.push_back(v);}
      else if(v==1){res.push_back(v);}
      else{
        while(res.size()!=0 && (res[res.size()-1]+1)!=v){res.pop_back();}
        res[res.size()-1]++;
      }
      output(res);
    }
  }
  return 0;
}