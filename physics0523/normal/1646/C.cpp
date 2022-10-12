#include<bits/stdc++.h>

using namespace std;

long long lldsumb(long long x,long long b){long long r=0;while(x){r+=(x%b);x/=b;}return r;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  vector<long long> fcs;
  long long v=6;
  for(long long i=4;v<=5e12;i++){
    fcs.push_back(v);
    v*=i;
  }

  int cd=fcs.size();
  while(t>0){
    t--;
    long long n;
    int res=1e9;
    cin >> n;
    for(int i=0;i<(1<<cd);i++){
      long long sum=0;
      for(int j=0;j<cd;j++){
        if(i&(1<<j)){sum+=fcs[j];}
      }
      if(n<sum){continue;}
      res=min(res,(int)(lldsumb(i,2)+lldsumb(n-sum,2)));
    }
    cout << res << '\n';
  }
  return 0;
}