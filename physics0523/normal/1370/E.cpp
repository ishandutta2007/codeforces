#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s,t;
  cin >> n >> s >> t;
  string ss=s,st=t;
  sort(ss.begin(),ss.end());
  sort(st.begin(),st.end());
  if(ss!=st){cout << "-1\n";return 0;}
  string mem;
  for(int i=0;i<n;i++){
    if(s[i]!=t[i]){
      mem.push_back(s[i]);
    }
  }

  int sz=mem.size();
  mem=mem+mem+mem;
  string cvrt;
  for(int i=1;i<mem.size();i++){
    if(mem[i-1]!=mem[i]){
      for(int j=0;j<sz;j++){
        cvrt.push_back(mem[i+j]);
      }
      break;
    }
  }

  int res=0;
  int z=0,o=0;
  for(int i=0;i<cvrt.size();i++){
    if(cvrt[i]=='0'){
      if(z>0){z--;}
      else{res++;}
      o++;
    }
    else{
      if(o>0){o--;}
      else{res++;}
      z++;
    }
  }
  cout << res << '\n';
  return 0;
}