#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  if(n<=9){cout << "-1\n";return 0;}
  if(n%25==0){cout << "0\n";return 0;}
  string s=to_string(n);
  vector<string> lis={"25","50","75","00"};
  int res=1e9;
  for(auto &nx : lis){
    string cur=s;
    int cr=0;
    //tail
    bool err=false;
    for(int i=cur.size()-1;i>=0;i--){
      if(cur[i]==nx[1]){
        for(int j=i+1;j<cur.size();j++){
          swap(cur[j-1],cur[j]);
          cr++;
        }
        break;
      }
      if(i==0){err=true;}
    }
    if(err){continue;}

    for(int i=cur.size()-2;i>=0;i--){
      if(cur[i]==nx[0]){
        for(int j=i+1;j<cur.size()-1;j++){
          swap(cur[j-1],cur[j]);
          cr++;
        }
        break;
      }
      if(i==0){err=true;}
    }
    if(err){continue;}
    for(int i=0;i<cur.size();i++){
      if(cur[i]!='0'){
        for(int j=0;j<i;j++){
          swap(cur[j],cur[j+1]);
          cr++;
        }
        break;
      }
    }
    //cout << nx << ' ' << cur << '\n';
    if(cur[cur.size()-2]!=nx[0]){err=true;}
    if(cur[cur.size()-1]!=nx[1]){err=true;}
    if(err){continue;}
    //cout << nx << ' ' << cur << '\n';
    res=min(res,cr);
  }
  if(res>1e8){res=-1;}
  cout << res << '\n';
  return 0;
}