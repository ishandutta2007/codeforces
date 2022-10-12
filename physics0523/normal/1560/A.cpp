#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> seq;
  for(int i=1;i<=10000;i++){
    if(i%3!=0 && i%10!=3){seq.push_back(i);}
  }
  int t;
  cin >> t;
  while(t>0){
    t--;
    int v;
    cin >> v;
    cout << seq[v-1] << '\n';
  }
  return 0;
}