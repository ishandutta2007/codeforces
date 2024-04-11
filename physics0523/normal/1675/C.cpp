#include<bits/stdc++.h>

using namespace std;

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
    int p=0,q=l-1;
    for(int i=0;i<l;i++){
      if(s[i]=='1'){p=max(p,i);}
      else if(s[i]=='0'){q=min(q,i);}
    }
    cout << q-p+1 << '\n';
  }
  return 0;
}