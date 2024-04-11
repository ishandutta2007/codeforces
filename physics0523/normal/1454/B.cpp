#include<bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    map<int,int> mem;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
      cin >> a[i];
      mem[a[i]]++;
    }
    int res=10000000;
    for(int i=1;i<=n;i++){
      if(mem[a[i]]==1){
        res=min(a[i],res);
      }
    }
    if(res==10000000){cout << "-1\n";continue;}
    for(int i=1;i<=n;i++){
      if(a[i]==res){cout << i << '\n';}
    }
  }
  return 0;
}