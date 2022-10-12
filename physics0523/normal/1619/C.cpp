#include<bits/stdc++.h>

using namespace std;

string wa(long long a,long long b){
  string pre;
  while(a>0 || b>0){
    pre.push_back('0'+a%10+b%10);
    a/=10;b/=10;
  }
  reverse(pre.begin(),pre.end());
  string res;
  for(auto &nx : pre){
    if(nx<='9'){res.push_back(nx);}
    else{
      res.push_back('1');
      res.push_back(nx-10);
    }
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
    long long a,ma,s;
    cin >> a >> s;
    ma=a;
    string sb,ss=to_string(s);
    while(s>0){
      if(a%10<=s%10){
        sb.push_back('0'+(s%10)-(a%10));
        a/=10;s/=10;
      }
      else{
        sb.push_back('0'+10+(s%10)-(a%10));
        a/=10;s/=100;
      }
    }
    reverse(sb.begin(),sb.end());
    long long b=stoll(sb);
    //cout << ma << ' ' << b << ' ' << wa(ma,b) << '\n';
    if(ss==wa(ma,b)){
      cout << b << '\n';
    }
    else{
      cout << "-1\n";
    }
  }
  return 0;
}