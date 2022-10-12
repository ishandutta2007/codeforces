#include<bits/stdc++.h>

using namespace std;

vector<int> solve3(int n){
  vector<int> res;
  if(n%2==1){
    res.push_back(1);
    res.push_back((n-1)/2);
    res.push_back((n-1)/2);
    return res;
  }
  if(n%4==2){
    res.push_back(2);
    res.push_back((n-2)/2);
    res.push_back((n-2)/2);
  }
  res.push_back(n/2);
  res.push_back(n/4);
  res.push_back(n/4);
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> a;
    for(int i=0;i<k-3;i++){
      a.push_back(1);
      n--;
    }
    vector<int> last=solve3(n);
    a.push_back(last[0]);
    a.push_back(last[1]);
    a.push_back(last[2]);
    for(int i=0;i<k;i++){
      if(i){cout << " ";}
      cout << a[i];
    }cout << '\n';
  }
  return 0;
}