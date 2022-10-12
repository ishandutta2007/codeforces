#include<bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t>0){t--;
    int n;
    string s;
    cin >> n >> s;
    int res=0,wc=0,tp=1;
    for(int i=0;i<n;i++){
      if(s[i]=='0'){
        if(tp==0){res+=max(0,2-wc);}
        tp=0;wc=0;
      }
      else{wc++;}
    }
    cout << res << '\n';
  }
}