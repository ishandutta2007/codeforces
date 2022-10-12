#include<bits/stdc++.h>
#define mod 1000000007

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
    int sa;
    vector<int> a(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
      if(i==0){sa=a[i];}
      else{sa=sa&a[i];}
    }
    long long res=1;
    int ok=0;
    for(int i=0;i<n;i++){
      if((sa|a[i])==sa){ok++;}
    }
    res=ok;
    res*=(ok-1);res%=mod;
    for(int i=n-2;i>=1;i--){
      res*=i;res%=mod;
    }
    cout << res << '\n';
  }
  return 0;
}