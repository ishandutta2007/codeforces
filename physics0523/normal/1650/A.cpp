#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s,c;
    cin >> s >> c;
    int l=s.size();
    bool isok=false;
    for(int i=0;i<l;i++){
      if(c[0]==s[i]){
        if(i%2==0 && (l-1-i)%2==0){isok=true;}
      }
    }
    if(isok){cout << "Yes\n";}
    else{cout << "No\n";}
  }
  return 0;
}