#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,c=0;
    string s;
    cin >> n >> s;
    for(int i=n-1;i>=0;i--){
      if(s[i]==')'){c++;}
      else{break;}
    }
    if(c>(n-c)){cout << "Yes\n";}
    else{cout << "No\n";}
  }
}