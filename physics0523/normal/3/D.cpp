#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int cq(string &s){
  int res=0;
  for(auto &nx : s){
    if(nx=='?'){res++;}
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int l=s.size();
  int q=cq(s);
  vector<long long> a(q),b(q);
  string qr;
  for(int i=0;i<q;i++){
    cin >> a[i] >> b[i];
    qr.push_back(')');
  }

  long long gv=0;
  int gh=0;
  priority_queue<pl,vector<pl>,greater<pl>> pq;
  int curq=0;
  for(int i=0;i<l;i++){
    if(s[i]=='('){gh++;}
    else if(s[i]==')'){
      gh--;
      if(gh<0){
        if(pq.empty()){cout << "-1\n";return 0;}
        pl od=pq.top();pq.pop();
        gv+=od.first;
        qr[od.second]='(';
        gh+=2;
      }
    }
    else{
      gv+=b[curq];
      pq.push({a[curq]-b[curq],curq});
      gh--;
      if(gh<0){
        if(pq.empty()){cout << "-1\n";return 0;}
        pl od=pq.top();pq.pop();
        gv+=od.first;
        qr[od.second]='(';
        gh+=2;
      }
      curq++;
    }
    // cout << gv << ' ' << gh << '\n';
  }
  if(gh!=0){cout << "-1\n";return 0;}
  cout << gv << '\n';
  curq=0;
  for(int i=0;i<l;i++){
    if(s[i]=='?'){
      cout << qr[curq];
      curq++;
    }
    else{cout << s[i];}
  }cout << '\n';
}