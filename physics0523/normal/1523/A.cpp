#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    string s;
    cin >> n >> m >> s;
    for(int i=0;i<m;i++){
      string ns=s;
      for(int j=0;j<n;j++){
        int cnt=0;
        if(j!=0 && s[j-1]=='1'){cnt++;}
        if(j!=(n-1) && s[j+1]=='1'){cnt++;}
        if(cnt==1){ns[j]='1';}
      }
      if(s==ns){break;}
      s=ns;
    }
    cout << s << '\n';
  }
  return 0;
}