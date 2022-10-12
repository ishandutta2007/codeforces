#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,m;
    cin >> n >> m;
    if(n>m){
      cout << "No\n";
      continue;
    }
    if(n==1){
      cout << "Yes\n";
      cout << m << "\n";
      continue;
    }
    if(n==m){
      cout << "Yes\n";
      for(int i=0;i<n;i++){
        if(i){cout << " ";}
        cout << "1";
      }cout << "\n";
      continue;
    }
    if(n%2){
      cout << "Yes\n";
      for(int i=0;i<n;i++){
        if(i){cout << " ";}
        if(i){cout << "1";}
        else{cout << m-n+1;}
      }cout << "\n";
      continue;
    }

    long long mg=m-n;
    if(mg%2==0){
      cout << "Yes\n";
      for(int i=0;i<n;i++){
        if(i){cout << " ";}
        if(i<=1){cout << 1+(mg/2);}
        else{cout << 1;}
      }cout << "\n";
    }
    else{
      cout << "No\n";
    }
  }
  return 0;
}