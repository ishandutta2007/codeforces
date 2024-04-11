#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m,k;
    cin >> n >> m >> k;
    string a,b;
    cin >> a >> b;

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());

    int cnt=0;
    string res;
    while(a.size()>0 && b.size()>0){
      if(cnt==k){
        res.push_back(b.back());
        b.pop_back();
        cnt=-1;
      }
      else if(cnt==-k){
        res.push_back(a.back());
        a.pop_back();
        cnt=1;
      }
      else if(a.back()<b.back()){
        res.push_back(a.back());
        a.pop_back();
        if(cnt>0){cnt++;}else{cnt=1;}
      }
      else{
        res.push_back(b.back());
        b.pop_back();
        if(cnt>=0){cnt=-1;}else{cnt--;}
      }
    }
    cout << res << '\n';
  }
  return 0;
}