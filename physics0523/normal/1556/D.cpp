#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> qor(n),qand(n);
  for(int i=0;i<n;i++){
    cout << "or " << 1+(i)%n << ' ' << 1+(i+1)%n << '\n';
    fflush(stdout);
    cin >> qor[i];
    cout << "and " << 1+(i)%n << ' ' << 1+(i+1)%n << '\n';
    fflush(stdout);
    cin >> qand[i];
  }
  vector<int> res(n,0);
  for(int i=0;i<30;i++){
    int cur=-1;
    for(int j=0;j<3*n;j++){
      if((qor[j%n]&(1<<i)) == (qand[j%n]&(1<<i))){
        if((qor[j%n]&(1<<i))){cur=1;}else{cur=0;}
      }
      else{
        if(cur!=-1){cur=1-cur;}
      }
      if(cur==1){res[(j+1)%n]|=(1<<i);}
    }
  }

  sort(res.begin(),res.end());
  cout << "finish" << ' ' << res[k-1] << '\n';
  fflush(stdout);
  return 0;
}