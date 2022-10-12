#include<bits/stdc++.h>

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
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    if(n==1){cout << "0\n";continue;}
    long long res=n-1;
    for(long long i=0;i<n;i++){
      for(long long j=i+1;j<n;j++){
        vector<long long> cur=a;

        for(auto &nx : cur){nx*=(j-i);}
        long long step=(cur[j]-cur[i])/(j-i);
        long long start=cur[i]-step*i;
        long long cop=0;
        for(long long k=0;k<n;k++){
          if((start+step*k)!=cur[k]){cop++;}
        }
        res=min(res,cop);
      }
    }
    cout << res << '\n';
  }
  return 0;
}