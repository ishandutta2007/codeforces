#include<bits/stdc++.h>

using namespace std;

bool isprime(int x){
  for(int i=2;i*i<=x;i++){
    if(x%i==0){return false;}
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int k;
    string s;
    cin >> k >> s;
    bool fl=false;
    for(auto &nx : s){
      if(nx!='2' && nx!='3' && nx!='5' && nx!='7'){
        cout << 1 << '\n';
        cout << nx << '\n';
        fl=true;
        break;
      }
    }
    if(fl){continue;}
    for(int i=0;i<s.size();i++){
      for(int j=i+1;j<s.size();j++){
        if(!isprime((s[i]-'0')*10+(s[j]-'0'))){
          cout << 2 << '\n';
          cout << s[i] << s[j] << '\n';
          fl=true;break;
        }
      }
      if(fl){break;}
    }
    // ans must be <=2
    // proof:
    // 2dig with 2,3,5,7 ... 23,37,53,73
    // there are no chain >=3
  }
  return 0;
}