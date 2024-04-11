#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  map<long long,long long> mp;
  set<long long> st;
  st.insert(0);
  
  long long q;
  cin >> q;
  while(q>0){
    q--;
    string s;
    long long x;
    cin >> s >> x;
    if(s[0]=='+'){
      st.insert(x);
    }
    else{
      long long cur=mp[x];
      while(st.find(cur)!=st.end()){
        cur+=x;
      }
      mp[x]=cur;
      cout << cur << "\n";
    }
  }

  return 0;
}