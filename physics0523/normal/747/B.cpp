#include<bits/stdc++.h>

using namespace std;

int mem[256]={0};
string cl="ACGT";

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  mem['A']=0;mem['C']=1;
  mem['G']=2;mem['T']=3;
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> bk(4,0);
  for(auto &nx : s){if(nx!='?'){bk[mem[nx]]++;}}
  for(int i=0;i<n;i++){
    if(s[i]=='?'){
      int tg=0;
      for(int j=0;j<4;j++){
        if(bk[tg]>bk[j]){tg=j;}
      }
      s[i]=cl[tg];
      bk[tg]++;
    }
  }
  if(bk[0]==bk[1] && bk[1]==bk[2] && bk[2]==bk[3]){
    cout << s << '\n';
  }
  else{cout << "===\n";}
  return 0;
}