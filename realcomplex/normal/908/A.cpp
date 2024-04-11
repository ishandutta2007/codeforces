#include <bits/stdc++.h>

using namespace std;

int main(){
  string a;
  cin >> a;
  int ans = 0;
  for(char x : a){
    if(x>='0'&&x<='9'){
      if(x%2==1)ans++;
    }
    else{
      if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u')
        ans++;
    }
  }
  cout << ans;
  return 0;
}