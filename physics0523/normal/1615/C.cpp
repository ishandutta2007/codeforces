#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    int res=1e9;
    int g,b;
    g=0;b=0;
    for(int i=0;i<n;i++){
      if(s1[i]=='1' && s2[i]=='0'){g++;}
      if(s1[i]=='0' && s2[i]=='1'){b++;}
    }
    if(g==b){res=min(res,g+b);}
    g=0;b=0;
    for(int i=0;i<n;i++){
      if(s1[i]=='1' && s2[i]=='1'){g++;}
      if(s1[i]=='0' && s2[i]=='0'){b++;}
    }
    if(g==b+1){res=min(res,g+b);}
    if(res>1e8){res=-1;}
    cout << res << '\n';
  }
  return 0;
}