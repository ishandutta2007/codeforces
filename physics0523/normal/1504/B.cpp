#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l;
    string s,t;
    cin >> l >> s >> t;
    int sc=0,tc=0;
    bool fl=true;
    int tg=0;
    for(int i=0;i<l;i++){
      sc+=(2*(s[i]-'0')-1);
      tc+=(2*(t[i]-'0')-1);
      if(sc==0 && tc==0){
        if(s[i]!=t[i]){for(int j=tg;j<=i;j++){s[j]=('0'+'1'-s[j]);}}
        tg=i+1;
      }
    }
    if(s!=t){fl=false;}
    if(fl){cout << "YES\n";}else{cout << "NO\n";}
  }
  return 0;
}