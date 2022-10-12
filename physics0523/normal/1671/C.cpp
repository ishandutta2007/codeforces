#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,x;
    cin >> n >> x;
    vector<long long> a(n);
    long long sum=0;
    for(auto &nx : a){
      cin >> nx;
      sum+=nx;
    }
    sort(a.begin(),a.end());

    long long del=0,res=0;
    for(long long i=n;i>=1;i--){
      long long mergin=x-(sum+del*i);
      if(mergin>=0){
        long long pass=1+(mergin/i);
        res+=i*pass;
        del+=pass;
      }
      sum-=a[i-1];
    }
    cout << res << '\n';
  }
  return 0;
}