#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m; 
  cin >> n >> m;
  if(m==2){
    cout << "2 2\n1 2 1\n2 3 1";
    return 0;
  }
  else if(m==1){
    cout << "2 2\n1 2 2\n";
    return 0;
  }
  if(n==3 and m==3){
    cout << "2 2\n 1 2 1\n 2 3 1\n1 3 2";
    return 0;
  }
  m-=2;
  cout << "2 100003\n1 2 1\n2 " << n << " 1\n";
  int l = 100001;
  int last = n;
  for(int j = 3;j<=n-1;j++){
    if(j==n-1){
      cout << last << " " << j << " " << l << "\n";
      m--;
      l=0;
    }
    else{
      cout << last << " " << j << " "<< 1 << "\n";
      m--;
      l--;
    }
    last=j;
  }
  for(int i = 1;i<=n;i++){
     if(m==0)break;
     for(int j = i+1;j<=n;j++){
       if(i==1){
         if(j==2 or m==0)continue;
         if(j==n){
           cout << i << " " << j << " " << 2 << "\n";
           m--;
           continue; 
         }
         cout << i << " " << j << " " << (int)1e9 << "\n";
         m--;
       }
       else if(i==2){
         if(j==n or m==0)continue;
         cout << i << " " << j << " " << (int)1e9 << "\n";
         m--;
       }
       else{
         if(m==0 or j==i+1 or(i==3 and j==n))continue;
         cout << i << " " << j << " " << (int)1e9 << "\n";
         m--;
       }
     }
  }
  return 0;
}