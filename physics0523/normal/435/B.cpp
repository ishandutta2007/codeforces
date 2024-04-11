#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int k;
  cin >> s >> k;
  int l=s.size();
  for(int i=0;i<l;i++){
    int tg=i;
    for(int j=i;j<l;j++){
      if((j-i)>k){break;}
      if(s[tg]<s[j]){tg=j;}
    }
    for(int j=(tg-1);j>=i;j--){
      swap(s[j],s[j+1]);
      k--;
    }
  }
  cout << s << "\n";
  return 0;
}