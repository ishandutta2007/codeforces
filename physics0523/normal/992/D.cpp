#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long n,k;
  cin >> n >> k;
  vector<pair<long long,long long>> pv;
  long long v,c=1;
  cin >> v;
  pv.push_back(make_pair(v,1));
  for(int i=1;i<n;i++){
    cin >> v;
    if(pv[c-1].first==1 && v==1){
      pv[c-1].second++;
    }
    else{
      pv.push_back(make_pair(v,1));
      c++;
    }
  }
  long long res=0;
  if(k==1){res+=n;}
  for(int i=0;i<c;i++){
    for(int j=1;j<=pv[i].second;j++){
      long long p=pv[i].first;
      long long s=pv[i].first*j;
      for(int l=i+1;l<c;l++){
        if(pv[l].second==1){
          double prm=((double)p);
          prm*=((double)pv[l].first);
          if(prm>4.0e18){break;}
          p*=pv[l].first;
          s+=pv[l].first;
          if(p==s*k){res++;}
        }
        else{
          if(p%k==0){
            if(s+1<=(p/k) && (p/k)<=s+pv[l].second){res++;}
          }
          s+=pv[l].second;
        }
      }
    }
  }
  cout << res << '\n';
}