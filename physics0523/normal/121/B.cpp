#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  string s;
  cin >> n >> k >> s;
  int i=0;
  while(k>0){
    while(i<(n-1)){
      if(i<(n-2)){
        if((i%2)==0 && s[i]=='4' && (s[i+1]=='4' || s[i+1]=='7') && s[i+2]=='7'){
          k%=2;
        }
      }
      if(k==0){break;}

      if(s[i]=='4' && s[i+1]=='7'){
        k--;
        if(i%2==0){s[i+1]='4';}
        else{s[i]='7';}
        i=max(i-1,0);
        break;
      }
      i++;
    }
    if(i==(n-1)){break;}
  }
  cout << s << '\n';
  return 0;
}