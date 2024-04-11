#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> zp;
  int ld=1;

  for(int i=0;i<n;i++){
    if(s[i]=='0'){
      if(ld){continue;}
      zp.push_back(i);
    }
    else{
      ld=0;
    }
  }

  if(zp.empty()){
    int jd=1;
    for(int i=0;i<n;i++){
      if(s[i]=='1'){jd=0;}
      if(jd==0){cout << s[i];}
    }
    if(jd){cout << "0";}
    cout << "\n";
    return 0;
  }

  int lv=-1,ofs=0;

  for(int i=0;i<=zp[0];i++){
    int clv=1e9;
    for(int j=0;j<zp.size();j++){
      int pos=zp[j]-i;
      if(s[pos]=='0'){clv=j;break;} // 50% chance to break
    }
    // cout << i << " " << clv << "\n";
    if(lv<clv){lv=clv;ofs=i;}
  }

  int jd=1;
  for(int i=0;i<n;i++){
    char cur=s[i];
    if(i-ofs>=0 && s[i-ofs]=='1'){cur='1';}
    if(cur=='1'){jd=0;}
    if(jd==0){cout << cur;}
  }
  if(jd){cout << "0";}
  cout << "\n";

  return 0;
}