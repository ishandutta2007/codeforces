#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    string s;
    cin >> n >> s;
    int c=0;
    for(int i=0;i<n;i++){
      if((s[i]-'0')%2==1){c++;}
    }
    if(c<2){cout << -1 << "\n";continue;}
    c=0;
    for(int i=0;i<n;i++){
      if((s[i]-'0')%2==1){
        c++;
        cout << s[i];
        if(c==2){break;}
      }
    }cout << '\n';
  }
}