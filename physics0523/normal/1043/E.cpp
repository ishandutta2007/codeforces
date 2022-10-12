#include<bits/stdc++.h>

using namespace std;

long long f(long long x1,long long y1,long long x2,long long y2){return min(x1+y2,x2+y1);}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long n,m;
  cin >> n >> m;
  vector<long long> x(n),y(n);
  vector<pair<long long,long long>> pv;
  for(long long i=0;i<n;i++){
    cin >> x[i] >> y[i];
    pv.push_back(make_pair(x[i]-y[i],i));
  }
  sort(pv.begin(),pv.end());
  vector<long long> lx(n),ry(n);
  
  lx[0]=x[pv[0].second];
  for(long long i=1;i<n;i++){lx[i]=lx[i-1]+x[pv[i].second];}
  
  ry[n-1]=y[pv[n-1].second];
  for(long long i=n-2;i>=0;i--){ry[i]=ry[i+1]+y[pv[i].second];}
  vector<long long> res(n);
  for(long long i=0;i<n;i++){
    long long v=pv[i].second;
    if(i!=0){
      //cout << lx[i-1] << '+' << y[v]*i << ',';
      res[v]+=lx[i-1];
      res[v]+=y[v]*i;
    }
    if(i!=n-1){
      //cout << ry[i+1] << '+' << x[v]*(n-1-i) << ',';
      res[v]+=ry[i+1];
      res[v]+=x[v]*(n-1-i);
    }
    //cout << v << '\n';
  }
  //for(long long i=0;i<n;i++){cout << res[i] << '\n';}
  for(long long i=0;i<m;i++){
    long long p,q;
    cin >> p >> q;
    p--;q--;
    res[p]-=f(x[p],y[p],x[q],y[q]);
    res[q]-=f(x[p],y[p],x[q],y[q]);
  }
  for(long long i=0;i<n;i++){
    if(i!=0){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}