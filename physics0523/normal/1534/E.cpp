#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int query(vector<int> &a){
  cout << "?";
  for(auto &nx : a){cout << ' ' << nx;}
  cout << '\n';
  fflush(stdout);
  int v;
  cin >> v;
  return v;
}

int main(){
  int n,k;
  cin >> n >> k;
  int q=-1;
  if(n%k==0){
    q=n/k;
  }
  else{
    for(int i=1;i<=500;i++){
      if((k*i)<n){continue;}
      if(((k*i)-n)%2){continue;}
      int cap=i;
      if(i%2==0){cap--;}
      if((cap*n)<i*k){continue;}
      q=i;break;
    }
  }
  if(q==-1){
    cout << "-1\n";
    fflush(stdout);
    return 0;
  }
  int sig=q*k;
  vector<int> rem(q,k);
  vector<vector<int>> a(q);
  for(int i=1;i<=n;i++){
    vector<pi> kh;
    for(int j=0;j<q;j++){
      if(rem[j]>0){kh.push_back({rem[j],j});}
    }
    sort(kh.begin(),kh.end());
    reverse(kh.begin(),kh.end());
    for(int j=0;j<kh.size();j+=2){
      //cout << sig << ' ' << kh[j].second << '\n';
      if(sig<=n-i){break;}
      if(j==0){
        a[kh[j].second].push_back(i);
        rem[kh[j].second]--;sig--;
      }
      else{
        a[kh[j-1].second].push_back(i);
        rem[kh[j-1].second]--;sig--;
        a[kh[j].second].push_back(i);
        rem[kh[j].second]--;sig--;
      }
    }
  }
  int res=0;
  for(auto &nx : a){res^=query(nx);}
  cout << "! " << res << '\n';
  fflush(stdout);
  return 0;
}