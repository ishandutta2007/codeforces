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
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    if(n==3){
      if(a[1]%2==0){cout << a[1]/2 << '\n';}
      else{cout << -1 << '\n';}
      continue;
    }
    long long cnt=0;
    bool ope=false;
    for(int i=1;i<n-1;i++){
      if(a[i]>=2){ope=true;}
      cnt+=a[i];
      if(a[i]%2){cnt++;}
    }
    if(!ope){cout << "-1\n";continue;}
    cout << llceil(cnt,2) << '\n';
  }
  return 0;
}