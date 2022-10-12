#include<bits/stdc++.h>

using namespace std;

long long lldsum(long long x){long long r=0;while(x){r+=(x%10);x/=10;}return r;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    if(n%2050){cout << "-1\n";continue;}
    cout << lldsum(n/2050) << '\n';
  }
  return 0;
}