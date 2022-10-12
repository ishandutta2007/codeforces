#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  stack<string> st;
  map<string,int> mp;

  int i=0,res=0;
  while(i<s.size()){
    if(s[i]==':'){i++;continue;}
    if(s[i]=='.'){
      mp[st.top()]--;
      st.pop();
      i++;
      continue;
    }
    if(s[i]==','){i++;continue;}

    string cur;
    for(int j=i;;j++){
      if('A'<=s[j] && s[j]<='Z'){cur.push_back(s[j]);}
      else{i=j;break;}
    }
    res+=mp[cur];
    st.push(cur);
    mp[cur]++;
    //cout << cur << '\n';
  }
  cout << res << '\n';
  return 0;
}