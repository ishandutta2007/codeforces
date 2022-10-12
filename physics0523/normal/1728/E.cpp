#include<bits/stdc++.h>

using namespace std;

// https://qiita.com/drken/items/b97ff231e43bce50199a#3-4-%E6%8B%A1%E5%BC%B5%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95%E3%81%AE%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E7%9A%84%E8%A8%98%E8%BF%B0
// (x,y) will satisfy ax + by = gcd(a, b)
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<long long> d;
  long long bas=0;

  for(int i=0;i<n;i++){
    long long x,y;
    cin >> x >> y;

    bas+=y;
    d.push_back(x-y);
  }

  // cout << bas << "\n";

  sort(d.begin(),d.end());
  d.push_back(8e18);
  reverse(d.begin(),d.end());
  vector<long long> rd=d;
  rd[0]=0;
  for(int i=1;i<=n;i++){rd[i]+=rd[i-1];}

  int q;
  cin >> q;
  for(int i=0;i<q;i++){
    long long a,b,x,y;
    cin >> a >> b;
    long long g=extGCD(a,b,x,y);
    if(n%g){cout << "-1\n";continue;}

    long long ce=(n/g);
    x*=ce;y*=ce;
    long long dx=b/g,dy=-(a/g);

    if(x<0){
      long long ce=llceil(-x,dx);
      x+=ce*dx;
      y+=ce*dy;
    }
    else{
      long long ce=x/dx;
      x-=ce*dx;
      y-=ce*dy;
    }

    if(x<0 || y<0){cout << "-1\n";continue;}
    // cout << x << " " << y << "\n";

    long long res=0;
    long long l=0,r=y/(-dy);
    while(l<=r){
      long long te=(l+r)/2;
      long long xv=(x+te*dx)*a;
      // cout << i << " : " << xv << "\n";
      res=max(res,bas+rd[xv]);
      if(d[xv]>0){l=te+1;}
      else{r=te-1;}
    }
    cout << res << "\n";
  }
  return 0;
}