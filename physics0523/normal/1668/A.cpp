#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    if(n>m){swap(n,m);}
    if(n==1){
      if(m==1){cout << "0\n";}
      else if(m==2){cout << "1\n";}
      else{cout << "-1\n";}
    }
    else{
      if(n==m){cout << 2*(n-1) << '\n';}
      else if(n+1==m){cout << 2*n-1 << '\n';}
      else if((n+m)%2){cout << 2*m-3 << '\n';}
      else{cout << 2*m-2 << '\n';}
    }
  }
  return 0;
}