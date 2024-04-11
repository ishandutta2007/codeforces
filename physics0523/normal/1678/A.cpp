#include<bits/stdc++.h>

using namespace std;

int cntzero(vector<int> a){
  int res=0;
  for(auto &nx : a){
    if(nx==0){res++;}
  }
  return res;
}

bool isdistinct(vector<int> a){
  sort(a.begin(),a.end());
  int n=a.size();
  for(int i=1;i<n;i++){
    if(a[i-1]==a[i]){return false;}
  }
  return true;
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
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    int cz=cntzero(a);
    if(cz>0){
      cout << n-cz << '\n';
    }
    else if(isdistinct(a)){
      cout << n+1 << '\n';
    }
    else{
      cout << n << '\n';
    }
  }
  return 0;
}