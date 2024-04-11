#include<bits/stdc++.h>

using namespace std;

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,k;
  cin >> n >> k;
  vector<long long> a(n);
  for(auto &nx : a){cin >> nx;}
  vector<long long> stop(n,0);
  long long del=0,dd=0,res=0;
  for(int i=n-1;i>=0;i--){
    del-=dd;
    a[i]-=del;
    dd-=stop[i];
    //cout << i << ':' << del << ' ' << a[i] << '\n';
    if(a[i]<=0){continue;}
    long long len=min(k,(long long)(i+1));
    long long need=llceil(a[i],len);
    del+=need*len;
    dd+=need;
    res+=need;
    if((i-k)>=0){stop[i-k]+=need;}
  }
  cout << res << '\n';
  return 0;
}