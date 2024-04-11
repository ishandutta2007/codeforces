#include<bits/stdc++.h>

using namespace std;

long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t=1;
  while(t>0){
    t--;
    int n,d;
    cin >> n >> d;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    if(n<=2){cout << "0\n";continue;}
    long long res=0;
    int p=0;
    for(int i=2;i<n;i++){
      while((a[i]-a[p])>d){p++;}
      if(i-p+1>=3){res+=llnCr(i-p,2);}
    }
    cout << res << '\n';
  }
  return 0;
}