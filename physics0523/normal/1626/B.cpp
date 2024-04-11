#include<bits/stdc++.h>

using namespace std;

int add(char a,char b){
  int res=(a-'0')+(b-'0');
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    int l=s.size();
    bool isend=false;
    for(int i=l-2;i>=0;i--){
      int sm=add(s[i],s[i+1]);
      if(sm>=10){
        string ss=to_string(sm);
        s[i]=ss[0];s[i+1]=ss[1];
        cout << s << '\n';
        isend=true;break;
      }
    }
    if(isend){continue;}
    int sm=add(s[0],s[1]);
    cout << sm;
    for(int i=2;i<l;i++){cout << s[i];}
    cout << '\n';
  }
  return 0;
}