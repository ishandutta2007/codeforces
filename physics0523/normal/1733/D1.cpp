#include<bits/stdc++.h>

using namespace std;

string cvrt(int n,string &a,string &b){
  string res;
  for(int i=0;i<n;i++){
    if(a[i]==b[i]){res.push_back('0');}
    else{res.push_back('1');}
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    long long x,y;
    cin >> n >> x >> y;
    string a,b;
    cin >> a >> b;
    string s=cvrt(n,a,b);
    long long cnt=0;
    for(auto &nx : s){
      if(nx=='1'){cnt++;}
    }
    if(cnt%2){cout << "-1\n";continue;}
    if(cnt==0){cout << "0\n";continue;}
    if(cnt>=4){
      cout << (cnt/2)*y << "\n";
      continue;
    }
    else{
      int pt=0;
      for(int i=0;i<n;i++){
        if(s[i]=='1'){pt=i;break;}
      }
      if(s[pt+1]=='0'){
        cout << y << "\n";
        continue;
      }
      else{
        // n >= 5
        cout << min(2*y,x) << "\n";
        continue;
      }
    }
  }
  return 0;
}