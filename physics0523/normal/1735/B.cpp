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
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    long long mxm=2*a[0]-1;

    long long res=0;
    for(auto &nx : a){res+=llceil(nx,mxm);}
    cout << res-n << "\n";
  }
  return 0;
}