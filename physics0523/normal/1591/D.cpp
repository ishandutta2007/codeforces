#include<bits/stdc++.h>

using namespace std;

long long bsize;
long long sum(long long i,vector<long long> &bit){
    long long s=0;
    while(i>0){
        s+=bit[i];
        i-=i&(-i);
    }
    return s;
}
void add(long long i,long long x,vector<long long> &bit){
    while(i<=bsize){
        bit[i]+=x;
        i+=i&(-i);
    }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> mem(n+1,0);
    for(auto &nx : a){
      cin >> nx;
      mem[nx]++;
    }
    if(n==1){cout << "YES\n";continue;}
    if(n==2){
      if(a[0]<=a[1]){cout << "YES\n";}
      else{cout << "NO\n";}
      continue;
    }
    bool fl=false;
    for(auto &nx : mem){
      if(nx>=2){fl=true;}
    }
    if(fl){cout << "YES\n";continue;}
    vector<long long> bit(n+1,0);
    bsize=n;
    long long res=0;
    for(int i=0;i<n;i++){
      res+=i;
      res-=sum(a[i],bit);
      add(a[i],1,bit);
    }
    if(res%2){cout << "NO\n";}
    else{cout << "YES\n";}
  }
  return 0;
}