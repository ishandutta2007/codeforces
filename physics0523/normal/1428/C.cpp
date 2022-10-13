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
    cin >> s;
    l=s.size();
    stack<char> st;
    for(int i=0;i<l;i++){
      if(!st.empty()){if(s[i]=='B'){st.pop();continue;}}
      st.push(s[i]);
    }
    cout << st.size() << '\n';
  }
  return 0;
}