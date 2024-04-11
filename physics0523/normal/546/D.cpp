#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> mem(5123123,0);
  for(int i=2;i<5123123;i++){
    if(mem[i]!=0){continue;}
    for(int j=i;j<5123123;j+=i){
      int v=j;
      while(v%i==0){mem[j]++;v/=i;}
    }
  }
  for(int i=1;i<5123123;i++){
    mem[i]+=mem[i-1];
  }
  int t;
  cin >> t;
  while(t>0){
    t--;
    int a,b;
    cin >> a >> b;
    cout << mem[a]-mem[b] << '\n';
  }
  return 0;
}