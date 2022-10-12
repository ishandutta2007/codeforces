#include<bits/stdc++.h>

using namespace std;
long long gcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}
long long lcm(long long a,long long b){long long c=gcd(a,b);a/=c;return a*b;}

//  mod
//  -17  5  3 (-17  3 (mod. 5))
//  -17 % 5  -2 
inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

//  Euclid 
// ap + bq = gcd(a, b)  (p, q) d = gcd(a, b) 
long long extGcd(long long a, long long b, long long &p, long long &q) {
    if (b == 0) { p = 1; q = 0; return a; }
    long long d = extGcd(b, a%b, q, p);
    q -= a/b * p;
    return d;
}

// 
//  (r, m)  x  r (mod. m)
//  (0, -1) 
pair<long long, long long> ChineseRem(long long b1, long long m1, long long b2, long long m2) {
  long long p, q;
  long long d = extGcd(m1, m2, p, q); // p is inv of m1/d (mod. m2/d)
  if ((b2 - b1) % d != 0) return make_pair(0, -1);
  long long m = m1 * (m2/d); // lcm of (m1, m2)
  long long tmp = (b2 - b1) / d * p % (m2/d);
  long long r = mod(b1 + m1 * tmp, m);
  return make_pair(r, m);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m,g,l;
  long long k;
  cin >> n >> m >> k;
  vector<int> a(1048576,-1),b(1048576,-1);
  vector<long long> c(1048576,-1);
  for(int i=0;i<n;i++){
    int val;
    cin >> val;
    a[val]=i;
  }
  for(int i=0;i<m;i++){
    int val;
    cin >> val;
    b[val]=i;
  }

  g=gcd(n,m);l=lcm(n,m);
  //cout << g << ' ' << l << '\n';

  for(int i=0;i<1048576;i++){
    if(a[i]==-1 || b[i]==-1){continue;}
    if(a[i]%g!=b[i]%g){continue;}
    long long fix=a[i]%g;
    c[i]=fix+g*ChineseRem((a[i]-fix)/g,(n/g),(b[i]-fix)/g,(m/g)).first;
    c[i]%=l;
    //cout << i << ':' << c[i] << '\n';
  }

  long long st=0,fi=2000000000000000000,te;
  while(st<=fi){
    long long cnt=0;
    te=(st+fi)/2;
    for(int i=0;i<1048576;i++){
      if(c[i]==-1){continue;}
      cnt+=(te/l);
      if(c[i]<(te%l)){cnt++;}
    }
    cnt=te-cnt;
    //cout << te << ' ' << cnt << '\n';
    if(cnt<k){st=te+1;}
    else{fi=te-1;}
  }
  cout << st << '\n';
  return 0;
}