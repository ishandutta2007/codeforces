#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;

//Binary Indexed Tree
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
  long long t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    long long res=0;
    vector<long long> a(n);
    vector<long long> bit(n+10,0);
    bsize=n+3;

    set<long long> st;
    map<long long,long long> mp,exmp;
    for(int i=0;i<n;i++){
      cin >> a[i];
      st.insert(a[i]);
    }
    long long cv=1;
    for(auto &nx : st){mp[nx]=cv;cv++;}

    for(int i=0;i<n;i++){
      long long v=mp[a[i]];
      long long sm=sum(v-1,bit);
      long long ex=exmp[v];
      long long lg=i-sm-ex;
      res+=min(sm,lg);
      add(v,1,bit);
      exmp[v]++;
    }
    cout << res << '\n';
  }
  return 0;
}