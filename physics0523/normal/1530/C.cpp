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
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    vector<long long> b(n);
    for(auto &nx : b){cin >> nx;}
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    for(int i=1;i<n;i++){b[i]+=b[i-1];}
    long long as=0,bs=0;
    priority_queue<long long,vector<long long>,greater<long long>> ap;
    for(long long i=0;i<n;i++){
      ap.push(a[i]);
      as+=a[i];
    }
    for(long long i=0;i<n;i++){
      if(i%4==3){
        long long od=ap.top();ap.pop();
        as-=od;
      }
    }
    for(long long i=n-1;;i++){
      long long sz=(i+1)-(i+1)/4;
      if(i!=n-1){
        as+=100;
        ap.push(100);
        if(i%4==3){
          long long od=ap.top();ap.pop();
          as-=od;
        }
      }
      bs=b[min(sz-1,n-1)];
      //cout << as << ' ' << bs << '\n';
      if(as>=bs){cout << i-(n-1) << '\n';break;}
    }
  }
  return 0;
}