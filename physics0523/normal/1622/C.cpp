#include<bits/stdc++.h>

using namespace std;

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    vector<long long> a(n);
    long long sig=0;
    for(auto &nx : a){
      cin >> nx;
      sig+=nx;
    }
    if(sig<=k){cout << "0\n";continue;}
    sort(a.begin(),a.end());
    long long res=(sig-k),del=0,hd=0;
    for(long long i=n-1;i>=1;i--){
      hd++;
      del+=a[i]-a[0];
      long long rem=(sig-k)-del;
      if(rem<=0){
        res=min(hd,res);
      }
      else{
        res=min(hd+llceil(rem,hd+1),res);
      }
    }
    cout << res << '\n';
  }
  return 0;
}