// https://codeforces.com/blog/entry/83771
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  s="*"+s+"0";
  vector<int> fl(n+3,0);
  vector<long long> rw(n+3,0);
  int l=-1;
  for(int i=1;i<=n+1;i++){
    if(s[i]=='0'){
      if(l==-1){continue;}
      int r=(i-1);
      for(int j=1;j<=(r-l+1);j++){
        int st=l+j-1,step=(r-l+1)-j;
        rw[st]+=(l-fl[j]);
        rw[st+1]-=(l-fl[j]);
        rw[st+1]++;
        rw[st+step+1]--;
        fl[j]=r-j+1;
      }
      l=-1;
    }
    else if(l==-1){l=i;}
  }

  for(int i=1;i<=n;i++){rw[i]+=rw[i-1];}

  long long res=0;
  for(int i=1;i<=n;i++){
    rw[i]+=rw[i-1];
    res+=rw[i];
  }
  cout << res << '\n';
  return 0;
}