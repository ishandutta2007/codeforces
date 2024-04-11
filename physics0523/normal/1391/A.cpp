#include<bits/stdc++.h>

using namespace std;

int main(){
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a;
    for(int i=0;i<n;i++){a.push_back(i+1);}
    shuffle(a.begin(),a.end(),engine); //everything is ok
    for(int i=0;i<n;i++){
      if(i){cout << " ";}
      cout << a[i];
    }cout << '\n';
  }
  return 0;
}