#include<bits/stdc++.h>
#define mod 998244853

using namespace std;

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int l=s.size();
  vector<long long> val(l+1);
  for(int i=1;i<=l;i++){
    val[i]=((val[i-1]*10)+(s[i-1]-'0'))%mod;
  }

  for(int i=1;i<=l-2;i++){
    if(i!=1 && s[0]=='0'){continue;}
    int st=max(i+1,i+(l-i)/2-10);
    for(int j=st;j<=l-1;j++){
      if(max(i,j-i)>l-j){break;}
      if(j-i!=1 && s[i]=='0'){continue;}
      if(l-j!=1 && s[j]=='0'){continue;}
      //cout << i << ' ' << j << '\n';
      long long fir=val[i];
      long long sec=(mod+val[j]-(val[i]*power(10,j-i))%mod)%mod;
      long long thi=(mod+val[l]-(val[j]*power(10,l-j))%mod)%mod;
      if((fir+sec)%mod==thi){
        for(int k=0;k<l;k++){
          if(k==i){cout << '+';}
          if(k==j){cout << '=';}
          cout << s[k];
        }cout << '\n';
        return 0;
      }
    }
  }

  for(int i=1;i<=l-2;i++){
    if(i!=1 && s[0]=='0'){continue;}
    int st=max(i+1,l-i-10);
    for(int j=st;j<=l-1;j++){
      if(max(i,j-i)>l-j){break;}
      if(j-i!=1 && s[i]=='0'){continue;}
      if(l-j!=1 && s[j]=='0'){continue;}
      //cout << i << ' ' << j << '\n';
      long long fir=val[i];
      long long sec=(mod+val[j]-(val[i]*power(10,j-i))%mod)%mod;
      long long thi=(mod+val[l]-(val[j]*power(10,l-j))%mod)%mod;
      if((fir+sec)%mod==thi){
        for(int k=0;k<l;k++){
          if(k==i){cout << '+';}
          if(k==j){cout << '=';}
          cout << s[k];
        }cout << '\n';
        return 0;
      }
    }
  }
  return 0;
}