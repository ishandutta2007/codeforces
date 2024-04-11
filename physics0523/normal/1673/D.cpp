#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

vector<long long> div(long long x){
  vector<long long> res;
  for(long long i=1;i*i<=x;i++){
    if(x%i==0){
      res.push_back(i);
      if(i*i!=x){res.push_back(x/i);}
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long b,q,y;
    cin >> b >> q >> y;
    long long c,r,z;
    cin >> c >> r >> z;

    int cnt=0;
    long long sl=-8e18,sr=8e18;
    if(c < b){cout << "0\n";continue;}
    if((c-b) % q != 0){cout << "0\n";continue;}
    long long dlt=(c-b)%lcm(q,r);
    if(c != b+dlt){cnt++;sl=c;}

    if(b+(y-1)*q < c+(z-1)*r){cout << "0\n";continue;}
    if(((b+(y-1)*q) - (c+(z-1)*r)) % q != 0){cout << "0\n";continue;}
    dlt=((b+(y-1)*q) - (c+(z-1)*r))%lcm(q,r);
    if(b+(y-1)*q != c+(z-1)*r+dlt){cnt++;sr=c+(z-1)*r;}

    if(r%q){cout << "0\n";continue;}
    if(cnt!=2){cout << "-1\n";continue;}

    // cout << "#\n";
    long long res=0;
    vector<long long> dr=div(r);
    for(auto &nx : dr){
      if(lcm(nx,q)==r){
        res+=(r/nx)*(r/nx);
        res%=mod;
      }
    }
    cout << res << '\n';
  }
  return 0;
}