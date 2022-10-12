#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    vector<long long> s(k);
    for(auto &nx : s){cin >> nx;}

    if(n==k){
      vector<long long> a(k);
      a[0]=s[0];
      for(int i=1;i<n;i++){
        a[i]=s[i]-s[i-1];
      }
      bool ok=true;
      for(int i=1;i<n;i++){
        if(a[i-1]>a[i]){ok=false;}
      }
      if(ok){cout << "Yes\n";}
      else{cout << "No\n";}
      continue;
    }

    vector<long long> a_suf(k-1);
    for(int i=1;i<k;i++){
      a_suf[i-1]=s[i]-s[i-1];
    }
    bool ok=true;
    for(int i=1;i<a_suf.size();i++){
      if(a_suf[i-1]>a_suf[i]){ok=false;}
    }
    if(!a_suf.empty()){
      long long rem=n-k+1;
      rem*=a_suf[0];
      if(s[0]>rem){ok=false;}
    }

    if(ok){cout << "Yes\n";}
    else{cout << "No\n";}
  }
  return 0;
}