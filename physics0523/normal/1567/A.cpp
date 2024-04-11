#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    for(int i=0;i<n;i++){t.push_back('.');}
    for(int i=0;i<n;i++){
      if(s[i]=='U'){t[i]='D';}
      if(s[i]=='D'){t[i]='U';}
    }
    for(int i=0;i<n-1;i++){
      if(t[i]=='.'){t[i]='L';t[i+1]='R';}
    }
    cout << t << '\n';
  }
  return 0;
}