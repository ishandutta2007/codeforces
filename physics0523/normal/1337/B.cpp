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
    int h,n,m;
    cin >> h >> n >> m;
    while(h>20 && n>0){
      n--;
      h/=2;h+=10;
    }
    while(m>0){
      m--;
      h-=10;
    }
    if(h<=0){cout << "YES\n";}
    else{cout << "NO\n";}
  }
}