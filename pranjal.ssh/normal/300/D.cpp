#include <bits/stdc++.h>
using namespace std;

#define INF 7340033

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define tr(x,it) for(auto it = (x).begin();it!=(x).end();++it)
#define ntr(x,it) for(auto it = (x).rbegin();it!=(x).rend();++it)
#define ufy(v) sort(all(v));(v).erase(unique(all((v))),(v).end())
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define MP make_pair
#define clr clear
#define rz resize
#define C(a,b) memset(a,b,sizeof(a))
#define ia(a,n) FOR(i,0,n-1)cin>>a[i]
#define ia1(a,n) FOR(i,1,n)cin>>a[i]
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
inline int norm(int x,int m=INF){if(x>=m)x%=m;if(x<0)x+=m;return x;}
inline int neg(int x,int m=INF){x=-x;return norm(x);}
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
typedef long double Num;
const Num PI = 3.141592653589793238462643383279L;
typedef complex<Num> Complex;

void fft_main(int n, Num theta, Complex a[]) {
    for(int m = n; m >= 2; m >>= 1) {
    int mh = m >> 1;
    Complex thetaI = Complex(0, theta);
    rep(i, mh) {
      Complex w = exp((Num)i*thetaI);
      for(int j = i; j < n; j += m) {
        int k = j + mh;
        Complex x = a[j] - a[k];
        a[j] += a[k];
        a[k] = w * x;
      }
    }
    theta *= 2;
  }
  int i = 0;
  reu(j, 1, n-1) {
    for(int k = n >> 1; k > (i ^= k); k >>= 1) ;
    if(j < i) swap(a[i], a[j]);
  }
}
void fft(int n, Complex a[]) { fft_main(n, 2 * PI / n, a); }
void inverse_fft(int n, Complex a[]) { fft_main(n, -2 * PI / n, a); }
void convolution(vector<Complex> &v, vector<Complex> &w) {
  int n = 1, vwn = v.size() + w.size() - 1;
  while(n < vwn) n <<= 1;
  v.resize(n), w.resize(n);
  fft(n, &v[0]);
  fft(n, &w[0]);
  rep(i, n) v[i] *= w[i];
  inverse_fft(n, &v[0]);
  rep(i, n) v[i] /= n;
}

int N,K;
vi ans[33];
void f(int n)
{
  if(n==1)
  {
    vi anss(K+1);
    anss[0]=1;
    ans[n]=anss;
    return;
  }

  f(n-1);
  vi t1=ans[n-1];

  vector<Complex> temp1(all(t1)),temp2(all(t1));
  

  convolution(temp1,temp2);
  
  FOR(i,0,K)
  {
    t1[i]=((ll)(temp1[i].real()+0.5))%INF;
  }
  temp1=vector<Complex>(all(t1));
  temp2=temp1;
  convolution(temp1,temp2);
  t1[0]=1;
  FOR(i,1,K)
  {
    t1[i]=((ll)(temp1[i-1].real()+0.5))%INF;
  }
  
  ans[n]=t1;  
}
int main()
{
     boost;
    K=1000;
    f(31);

    ans[0].pb(1); 
    ans[0].rz(K+1);
    
    TCASE
    {
      cin>>N>>K;
      int x=0;
      while (N>1 && N&1)
       x++, N>>=1;
      cout<<ans[x+1][K]<<"\n";
    }
  return 0;
}