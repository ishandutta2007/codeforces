#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  vector<int> a(n);
  int sig=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    sig+=a[i];
  }
  while(q>0){
    q--;
    int t,p;
    cin >> t >> p;
    if(t==2){
      if(sig>=p){cout << "1\n";}
      else{cout << "0\n";}
    }
    else{
      p--;
      sig-=a[p];
      a[p]=1-a[p];
      sig+=a[p];
      //cout << sig << '\n';
    }
  }
  return 0;
}