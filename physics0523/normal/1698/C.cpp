// WTF
// 1
// 4
// 1 1 -1 -1
#include<bits/stdc++.h>

using namespace std;

bool jud(vector<long long> &a){
  int n=a.size();
  set<long long> st;
  for(auto &nx : a){st.insert(nx);}
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      for(int k=j+1;k<n;k++){
        if(st.find(a[i]+a[j]+a[k])==st.end()){return false;}
      }
    }
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    int pos=0,neg=0,zer=0;
    for(auto &nx : a){
      if(nx>0){pos++;}
      else if(nx<0){neg++;}
      else{zer++;}
    }
    if(pos>=3){cout << "NO\n";continue;}
    if(neg>=3){cout << "NO\n";continue;}
    vector<long long> cvrt;
    for(auto &nx : a){
      if(nx>0){cvrt.push_back(nx);}
      if(nx<0){cvrt.push_back(nx);}
    }
    for(int i=0;i<min(5,zer);i++){cvrt.push_back(0);}
    if(jud(cvrt)){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}