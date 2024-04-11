#include <bits/stdc++.h>

using namespace std;

const int N = (int)6e5 + 9;
vector<string>s[N];
map<string,int>rez;
int main(){
  int n,q;
  cin >> n >> q;
  string a;
  while(n--){
    cin >> a;
    s[a.size()].push_back(a);
  } 
  int cnt,l,r;
  while(q--){
    cin >> a;
    if(rez[a]==1){
      cout << "YES\n";
      continue;
    }
    if(rez[a]==2){
      cout << "NO\n";
      continue;
    }
    cnt=0;
    l=a.size();
    r=s[l].size();
    for(int i = 0;i<r;i++){
      cnt=0;
      for(int j = 0;j<l;j++){
        if(s[l][i][j]!=a[j]){
          cnt++;
          if(cnt>1)break;
        }
      }
      if(cnt==1){
        cout << "YES\n";
        rez[a]=1;
        break;
      }
    }
    if(cnt!=1){
      cout << "NO\n";
      rez[a]=2;
    }
  }
  return 0;
}