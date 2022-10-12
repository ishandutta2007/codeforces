#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    string s;
    cin >> n >> k >> s;
    int res=0;
    int fi=0;
    for(int i=0;i<n;i++){if(s[i]=='*'){fi=i;}}
    int i=0;
    while(i<n){
      if(s[i]=='.'){i++;continue;}
      s[i]='x';res++;
      for(int j=i+k;j>=i;j--){
        if(i==j){i++;break;}
        if(s[j]=='*'){i=j;break;}
      }
    }
    if(s[fi]=='*'){res++;}
    cout << res << '\n';
  }
  return 0;
}