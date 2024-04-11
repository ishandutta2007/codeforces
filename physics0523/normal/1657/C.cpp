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
    string s;
    cin >> l >> s;
    int c=0,r=l,i=0;
    while((i+1)<l){
      if(s[i]==')' && s[i+1]=='('){
        int j=i+2;
        while(j<l){
          if(s[j]==')'){break;}
          j++;
        }
        if(j>=l){break;}
        c++;
        r-=(j-i+1);
        i=j+1;
      }
      else{c++;r-=2;i+=2;}
    }
    cout << c << ' ' << r << '\n';
  }
  return 0;
}