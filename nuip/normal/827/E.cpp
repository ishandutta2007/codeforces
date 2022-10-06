#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
const ll MOD=1e9+7;

typedef vector<int> vi;
#define repS(X,Y) reps(X,1,Y+1)
template<int B> // n <= 1<<B
struct FFT{
	typedef complex<double> cd;
	vi m2[B+1];
	vector<cd> power[2*(B+1)];
	FFT(){
		rep(e, B+1){
			m2[e].resize(1<<e);
			rep(m, 1<<e)rep(i,e) if(m&(1<<i)) m2[e][m] |= (1<<(e-1-i));
			
			power[  e].resize(1<<e);
			power[B+1+e].resize(1<<e);
			power[e][0] = power[B+1+e][0] = cd(1, 0);
			cd w(cos(acos(-1.0) / (1<<e)), sin(acos(-1.0) / (1<<e)));
			repS(j, (1<<e)-1){
				power[  e][j] = power[  e][j-1]*w;
				power[B+1+e][j] = power[B+1+e][j-1]*conj(w);
			}
		}
	}

	void transform(cd *f, int N, bool inv){
		int e;
		for(e=0;;e++) if(N == (1<<e)) break;
		rep(m,N)if(m < m2[e][m]) swap(f[m], f[m2[e][m]]);
		for(int t=0,t2=1;t2<N;t++,t2+=t2){
			cd *po = power[inv*(B+1) + t].data();
			for(int i=0;i<N;i+=t2+t2){
				for (int j = 0; j < (1<<t); j++) {
					cd x = f[i+j];
					cd y = f[i+t2+j] * po[j];
					f[i+j] = x + y;
					f[i+t2+j] = x - y;
				}
			}
		}
		if(inv) for(int i = 0; i < N; i++) f[i] /= N;
	}
	template <typename T>
	vector<cd> convolution(const vector<T> &f, const vector<T> &g){
		const int n = f.size(), m = g.size();
		int n2 = 1;
		while(n2 < 2*max(f.size(), g.size())) n2 *= 2;
		vector<cd> cf(n2), cg(n2);
		rep(i, n) cf[i] = f[i];
		rep(i, m) cg[i] = g[i];
		transform(cf.data(), n2, false);
		transform(cg.data(), n2, false);
		rep(i, n2) cf[i] *= cg[i];
		transform(cf.data(), n2, true);
		return cf;
	}
};
FFT<20> fft;

char str[512345];

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int n;
    scanf("%d%s",&n,str);
    vector<int> f(n),g(n);
    rep(i,n)
      if(str[i]=='V'){
	f[i]=1;
      }else if(str[i]=='K'){
	g[n-1-i]=1;
      }
    auto h=fft.convolution(f,g);
    //out(n,h.size(),h,1);
    vector<int> ng(n+1);
    reps(i,1,n) if(h[n-1+i].real()>0.1 ||
		   h[n-1-i].real()>0.1 ) ng[i]=1;
    int cnt=0;
    rreps(i,1,n+1)if(!ng[i]){
      for(int j=i+i;j<=n;j+=i)if(MX(ng[i],ng[j])) break;
      if(!ng[i]) ++cnt;
    }
    printf("%d\n",cnt);
    reps(i,1,n+1)if(!ng[i]) printf("%d ",i);
    puts("");
  }
  return 0;
}