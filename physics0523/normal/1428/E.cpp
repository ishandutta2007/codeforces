#include<bits/stdc++.h>
using namespace std;

int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}

long long calc(long long len,long long cnt){
  long long sho,lon;
  sho=(len/cnt);
  lon=(sho+1);
  long long sc,lc;
  lc=len-(sho*cnt);
  sc=cnt-lc;
  long long ct,res=0;
  ct=sho*sho;res+=ct*sc;
  ct=lon*lon;res+=ct*lc;
  return res;
}

int main(){
  long long n,k;
  cin >> n >> k;
  k-=n;
  vector<long long> a(n),cnt(n,1);
  for(int i=0;i<n;i++){cin >> a[i];}
  priority_queue<pair<long long,int>> pq;
  long long res=0;
  for(int i=0;i<n;i++){
    res+=calc(a[i],cnt[i]);
    pq.push(make_pair(calc(a[i],cnt[i])-calc(a[i],cnt[i]+1),i));
  }
  while(k>0){
    k--;
    pair<long long,int> cd=pq.top();
    //cout << cd.second << '\n';
    pq.pop();
    res-=cd.first;
    int cp=cd.second;
    cnt[cp]++;
    pq.push(make_pair(calc(a[cp],cnt[cp])-calc(a[cp],cnt[cp]+1),cp));
  }
  cout << res << '\n';
  return 0;
}