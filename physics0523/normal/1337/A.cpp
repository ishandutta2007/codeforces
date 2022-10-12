#include<bits/stdc++.h>

using namespace std;

bool isperm(vector<int> a){
  sort(a.begin(),a.end());
  int n=a.size();
  for(int i=0;i<n;i++){
    if(a[i]!=(i+1)){return false;}
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << b << ' ' << c << ' ' << c << '\n';
  }
}