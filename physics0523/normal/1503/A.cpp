#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l;
    string s;
    cin >> l >> s;
    string b1,b2;
    int oc=0;
    for(int i=0;i<l;i++){
      if(s[i]=='1'){oc++;}
      b1.push_back('-');
      b2.push_back('-');
    }
    if(oc%2){cout << "NO\n";continue;}
    int coc=0,rem=0;
    for(int i=0;i<l;i++){
      if(s[i]=='1'){
        if(coc<(oc/2)){b1[i]='(';b2[i]='(';}
        else{b1[i]=')';b2[i]=')';}
        coc++;
      }
      else{
        if(rem%2){b1[i]=')';b2[i]='(';}
        else{b1[i]='(';b2[i]=')';}
        rem++;
      }
    }
    int dp1=0,dp2=0;
    for(int i=0;i<l;i++){
      if(b1[i]=='('){dp1++;}else{dp1--;}
      if(b2[i]=='('){dp2++;}else{dp2--;}
      if(dp1<0 || dp2<0){break;}
    }
    if(dp1==0 && dp2==0){
      cout << "YES\n";
      cout << b1 << '\n';
      cout << b2 << '\n';
    }
    else{cout << "NO\n";}
  }
  return 0;
}