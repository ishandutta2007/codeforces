#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> rw(n+1,0);
    vector<int> pl,mn;
    for(int i=0;i<n;i++){
      rw[i+1]=rw[i];
      if(i%2==0){s[i]='+'+'-'-s[i];}
      if(s[i]=='+'){rw[i+1]++;pl.push_back(i);}
      else{rw[i+1]--;mn.push_back(i);}
    }
    while(q>0){
      q--;
      int l,r;
      cin >> l >> r;
      int val=abs(rw[r]-rw[l-1]);
      if(val==0){cout << 0 << '\n';}
      else if(val%2==0){cout << 2 << '\n';}
      else{cout << 1 << '\n';}
    }
  }
  return 0;
}