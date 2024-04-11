#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    map<int,int> mpmi,mpma;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      if(mpmi.find(v)==mpmi.end()){
        mpmi[v]=i;
        mpma[v]=i;
      }
      else{
        mpma[v]=i;
      }
    }
    for(int i=0;i<k;i++){
      int s,t;
      cin >> s >> t;
      if(mpmi.find(s)==mpmi.end()){cout << "NO\n";continue;}
      if(mpmi.find(t)==mpmi.end()){cout << "NO\n";continue;}
      if(mpmi[s]<=mpma[t]){cout << "YES\n";}
      else{cout << "NO\n";}
    }
  }
  return 0;
}