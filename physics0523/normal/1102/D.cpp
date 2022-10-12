#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  string res;
  for(int i=0;i<n;i++){res.push_back('*');}
  vector<int> bk(3,0);
  for(int i=0;i<n;i++){bk[s[i]-'0']++;}
  for(int i=0;i<n;i++){
    if(bk[s[i]-'0']<=(n/3)){res[i]=s[i];}
  }

  vector<int> resbk(3,0);
  for(int i=0;i<3;i++){
    if(bk[i]<=(n/3)){resbk[i]=bk[i];}
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<n;j++){
      if(resbk[i]>=(n/3)){break;}
      if(res[j]!='*'){continue;}
      if((s[j]-'0')!=i && bk[s[j]-'0']>(n/3) && bk[i]>(n/3)){continue;}
      if((s[j]-'0')!=i && bk[s[j]-'0']<=(n/3)){continue;}
      res[j]=('0'+i);
      resbk[i]++;
      bk[s[j]-'0']--;
      bk[i]++;
    }
  }

  cout << res << '\n';
  return 0;
}