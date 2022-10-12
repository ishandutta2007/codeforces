#include<bits/stdc++.h>

using namespace std;

void vecout(vector<long long> v){
  if(v.size()==0){cout << "-1\n";return;}
  cout << v.size() << '\n';
  long long fl=0;
  for(auto &nx: v){
    if(fl){cout << ' ';}
    fl=1;
    cout << nx;
  }
  cout << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long t;
  cin >> t;
  while(t>0){
    t--;
    long long n,w;
    cin >> n >> w;
    vector<long long> v(n+1);
    vector<long long> res;
    for(long long i=1;i<=n;i++){
      cin >> v[i];
      if(res.empty() && v[i]<=w && (v[i]*2)>=w){res.push_back(i);}
    }
    if(!res.empty()){vecout(res);continue;}
    long long cw=0;
    for(long long i=1;i<=n;i++){
      if(v[i]<=w){
        cw+=v[i];
        res.push_back(i);
        if(cw*2>=w){break;}
      }
    }
    if(cw*2<w){res.clear();}
    vecout(res);
  }
}