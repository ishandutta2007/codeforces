#include<bits/stdc++.h>

using namespace std;

long long llsankaku(long long x){return ((1+x)*x)/2;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    int l;
    l=s.size();
    long long res=0;
    for(int os=0;os<2;os++){
      int st=0,fi=0;
      while(fi<l){
        if(st<fi){st=fi;continue;}
        if(st==l){res+=(st-fi);fi++;continue;}
        if(s[st]=='?' || (s[st]-'0')==(os+st)%2){st++;}
        else{res+=(st-fi);fi++;}
      }
    }

    int cnt=0;
    for(int i=0;i<=l;i++){
      if(i!=l && s[i]=='?'){
        cnt++;
      }
      else{
        res-=llsankaku(cnt);
        cnt=0;
      }
    }
    cout << res << '\n';
  }
  return 0;
}