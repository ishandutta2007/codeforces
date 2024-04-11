#include<bits/stdc++.h>

using namespace std;

int main(){
ios::sync_with_stdio(false);
std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n+1);
    map<int,int> mem;
    a[0]=-1;
    for(int i=1;i<=n;i++){
      cin >> a[i];
      if(a[i]==a[i-1]){continue;}
      mem[a[i]]++;
    }
    mem[a[1]]--;
    mem[a[n]]--;
    int res=10000000;
    for(int i=1;i<=n;i++){
      res=min(mem[a[i]]+1,res);
    }
    cout << res << '\n';
  }
  return 0;
}