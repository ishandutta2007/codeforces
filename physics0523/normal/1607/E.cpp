#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int h,w;
    string s;
    cin >> h >> w >> s;
    int ch=0,cw=0;
    int mih=0,miw=0,mah=0,maw=0;
    int pt=s.size()-1;
    for(int i=0;i<s.size();i++){
      if(s[i]=='U'){ch--;}
      if(s[i]=='D'){ch++;}
      if(s[i]=='L'){cw--;}
      if(s[i]=='R'){cw++;}
      mih=min(mih,ch);
      mah=max(mah,ch);
      miw=min(miw,cw);
      maw=max(maw,cw);
      if(mah-mih+1>h){pt=i-1;break;}
      if(maw-miw+1>w){pt=i-1;break;}
    }
    ch=0;cw=0;
    mih=0;miw=0;mah=0;maw=0;
    for(int i=0;i<=pt;i++){
      if(s[i]=='U'){ch--;}
      if(s[i]=='D'){ch++;}
      if(s[i]=='L'){cw--;}
      if(s[i]=='R'){cw++;}
      mih=min(mih,ch);
      mah=max(mah,ch);
      miw=min(miw,cw);
      maw=max(maw,cw);
    }
    cout << 1-mih << ' ' << 1-miw << '\n';
  }
  return 0;
}