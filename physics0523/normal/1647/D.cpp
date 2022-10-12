#include<bits/stdc++.h>

using namespace std;

long long d;

bool isbt(long long v){
  if(v%d){return false;}
  v/=d;
  if(v%d){return true;}
  return false;
}

vector<long long> pfact(long long x){
  vector<long long> res;
  for(long long i=2;i*i<=x;i++){
    while(x%i==0){
      res.push_back(i);
      x/=i;
    }
  }
  if(x>1){res.push_back(x);}
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long x,ox;
    cin >> x >> d;
    ox=x;
    long long cnt=0;
    while(x%d==0){
      x/=d;
      cnt++;
    }
    if(cnt==1){cout << "NO\n";continue;}
    vector<long long> px=pfact(x);
    if(px.size()>=2){cout << "YES\n";continue;}
    vector<long long> pd=pfact(d);
    if(pd.size()==1){cout << "NO\n";continue;}
    cnt--;
    if(cnt==1){cout << "NO\n";continue;}
    if(cnt>=3){cout << "YES\n";continue;}
    bool isok=false;
    for(long long i=d;i*i<=ox;i+=d){
      long long j=(ox/i);
      if(isbt(i)&&isbt(j)){isok=true;}
    }
    if(isok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}