#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    vector<long long> a(n),b(n);
    for(auto &nx : a){cin >> nx;}
    for(auto &nx : b){cin >> nx;}

    vector<long long> b0,b1;
    for(int i=0;i<n;i++){
      if(a[i]==0){b0.push_back(b[i]);}
      else{b1.push_back(b[i]);}
    }
    sort(b0.begin(),b0.end());
    sort(b1.begin(),b1.end());

    if(b0.empty() || b1.empty()){
      long long res=0;
      for(auto &nx : b){res+=nx;}
      cout << res << "\n";
      continue;
    }

    deque<long long> mem_d0,mem_d1;
    for(auto &nx : b0){mem_d0.push_back(nx);}
    for(auto &nx : b1){mem_d1.push_back(nx);}

    long long res=0;
    {
      // 010101
      deque<long long> d0=mem_d0,d1=mem_d1;
      long long cres=d0.front();d0.pop_front();
      int prev=0;

      while((!d0.empty()) || (!d1.empty())){
        if(prev==0){
          if(!d1.empty()){
            cres+=2*d1.back();
            d1.pop_back();
            prev=1;
          }
          else{
            cres+=d0.back();
            d0.pop_back();
            prev=0;
          }
        }
        else{
          if(!d0.empty()){
            cres+=2*d0.back();
            d0.pop_back();
            prev=0;
          }
          else{
            cres+=d1.back();
            d1.pop_back();
            prev=1;
          }
        }
      }

      res=max(res,cres);
    }
    {
      // 101010
      deque<long long> d0=mem_d0,d1=mem_d1;
      long long cres=d1.front();d1.pop_front();
      int prev=1;

      while((!d0.empty()) || (!d1.empty())){
        if(prev==0){
          if(!d1.empty()){
            cres+=2*d1.back();
            d1.pop_back();
            prev=1;
          }
          else{
            cres+=d0.back();
            d0.pop_back();
            prev=0;
          }
        }
        else{
          if(!d0.empty()){
            cres+=2*d0.back();
            d0.pop_back();
            prev=0;
          }
          else{
            cres+=d1.back();
            d1.pop_back();
            prev=1;
          }
        }
      }
      
      res=max(res,cres);
    }
    cout << res << "\n";
  }
  return 0;
}