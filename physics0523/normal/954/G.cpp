#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,r;
  long long k;
  cin >> n >> r >> k;
  vector<long long> rw(n+1,0);
  for(int i=0;i<n;i++){
    long long v;
    cin >> v;
    rw[max(0,i-r)]+=v;
    rw[min(n,i+r+1)]-=v;
  }
  long long st=0,fi=1.1e18;
  while(st<=fi){
    long long ck=k;
    long long te=(st+fi)/2;
    vector<long long> crw=rw;
    for(int i=0;i<n;i++){
      if(crw[i]<te){
        long long dlt=te-crw[i];
        crw[i]+=dlt;
        crw[min(n,i+2*r+1)]-=dlt;
        ck-=dlt;
        if(ck<0){break;}
      }
      crw[i+1]+=crw[i];
    }
    if(ck<0){fi=te-1;}else{st=te+1;}
  }
  cout << fi << '\n';
  return 0;
}