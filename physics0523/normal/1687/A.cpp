#include<bits/stdc++.h>

using namespace std;

long long llsankaku(long long x){return ((1+x)*x)/2;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    long long bon;
    if(n<k){
      bon=llsankaku(k-1)-llsankaku(k-n-1);
      k=n;
    }
    else{bon=llsankaku(k-1);}
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    long long res=0;
    long long cur=0;
    for(int i=0;i<k;i++){cur+=a[i];}
    for(int i=0;i<n;i++){
      res=max(res,cur);
      cur-=a[i];
      if(i+k==n){break;}
      cur+=a[i+k];
    }
    cout << res+bon << '\n';
  }
  return 0;
}