#include <bits/stdc++.h>

using namespace std;

int main(){
  int h;
  cin >> h;
  int d[h+1];
  int cnt = 0; 
  bool perfect = true;
  for(int i = 0;i<=h;i++){
    cin >> d[i];
    if(d[i]>1){
      cnt++;
      if(cnt==2)perfect=false;
    }
    else cnt=0;
  }
  if(perfect==true){
    cout << "perfect\n";
    return 0;
  }
  cout << "ambiguous\n";
  cout << "0 ";
  cnt = 1;
  int last = 1;
  for(int i = 1;i<=h;i++){
     for(int j = 0;j<d[i];j++){
        cout << cnt << " ";
     }
     cnt += d[i];
  }
  cout << "\n0 ";
  bool has = false;
  cnt = 1;
  for(int i = 1;i<=h;i++){
    if(d[i]>=2 and d[i-1]>=2 and has==false){
      cout << cnt << " ";
      for(int j = 1;j<d[i];j++)cout << cnt-1 << " ";
      has=true;
    }
    else{
      for(int j = 0;j<d[i];j++)cout << cnt << " ";
    }
    cnt+=d[i];
  }
  return 0;
}