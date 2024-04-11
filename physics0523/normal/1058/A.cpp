#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int sig=0;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    sig+=v;
  }
  if(sig){cout << "HARD\n";}
  else{cout << "EASY\n";}
  return 0;
}