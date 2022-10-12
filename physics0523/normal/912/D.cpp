#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m,r,k;
  cin >> n >> m >> r >> k;
  vector<long long> vn,vm;
  long long nlim=n-r+1;
  long long mlim=m-r+1;
  for(long long i=2;vn.size()<n;i++){vn.push_back(min(min(r,nlim),i/2));}
  for(long long i=2;vm.size()<m;i++){vm.push_back(min(min(r,mlim),i/2));}
  reverse(vn.begin(),vn.end());
  reverse(vm.begin(),vm.end());
  priority_queue<long long,vector<long long>,greater<long long>> pq;
  for(auto &i : vn){
    for(auto &j : vm){
      //cout << i << ' ' << j << '\n';
      long long cv=i*j;
      pq.push(cv);
      if(pq.size()>k){
        long long od=pq.top();pq.pop();
        if(od==cv){break;}
      }
    }
  }
  long long res=0;
  while(!pq.empty()){
    long long nx=pq.top();pq.pop();
    res+=nx;
  }
  double dr=res;
  dr/=nlim;
  dr/=mlim;
  printf("%.12lf\n",dr);
  return 0;
}