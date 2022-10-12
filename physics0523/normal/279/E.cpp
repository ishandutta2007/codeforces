#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  string s;
  cin >> s;
  s="0"+s+"0";
  int n=s.size();
  vector<int> mem(n+1,0);
  for(int i=1;i<n;i++){
    if(s[i-1]!=s[i]){mem[i]=1;}
  }
  int res=0;
  for(int i=1;i<n;i++){
    if(mem[i]==1 && mem[i+1]==1){
      res++;
      mem[i]=0;mem[i+1]=0;
    }
  }
  for(int i=1;i<n;i++){res+=mem[i];}
  cout << res << '\n';
}