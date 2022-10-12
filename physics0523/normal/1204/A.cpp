#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  if(s=="0"){cout << "0\n";return 0;}
  int dig=s.size();
  if(dig%2==0){
    cout << (dig+1)/2 << "\n";
    return 0;
  }
  int zf=1;
  for(int i=1;i<dig;i++){
    if(s[i]=='1'){zf=0;}
  }
  if(zf==1){cout << dig/2 << "\n";}
  else{cout << (dig/2)+1 << "\n";}
  return 0;
}