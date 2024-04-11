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
    string s,t;
    cin >> n >> s >> t;
    if(s==t){cout << "YES\n";continue;}
    {
      string ss=s,st=t;
      sort(ss.begin(),ss.end());
      sort(st.begin(),st.end());
      if(ss!=st){cout << "NO\n";continue;}
    }

    int ac=0;
    for(auto &nx : s){
      if(nx=='a'){ac++;}
      if(nx=='c'){ac++;}
    }

    bool fl=true;
    int p=0,q=0;
    for(int i=0;i<ac;i++){
      while(s[p]=='b'){p++;}
      while(t[q]=='b'){q++;}
      // cout << s[p] << ' ' << t[q] << '\n';
      if(s[p]!=t[q]){fl=false;break;}
      if(s[p]=='a' && p>q){fl=false;break;}
      if(s[p]=='c' && p<q){fl=false;break;}
      p++;q++;
    }
    if(fl){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}