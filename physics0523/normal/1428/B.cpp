#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l,res=0;
    string s;
    cin >> l >> s;
    int tr=0,tl=0;
    for(int i=0;i<l;i++){
      if(s[i]=='>'){tr++;}
      if(s[i]=='<'){tl++;}
    }
    for(int i=0;i<l;i++){
      char p=s[i],q=s[(i+1)%l];
      if((p=='-')||(q=='-')){res++;continue;}
      if(p!=q){continue;}
      if(p=='>'){if(tl==0){res++;}}
      if(p=='<'){if(tr==0){res++;}}
    }
    cout << res << '\n';
  }
  return 0;
}