#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
void read(pp& x){ scanf("%d%d",&x.first, &x.second); }
void read(pll& x){ scanf("%lld%lld",&x.first, &x.second); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int AL = 10;

const int maxn = 210;

int n;
string s[maxn];
string t[maxn];
bitset<1<<(AL+1)> chk[maxn];

int main()
{
	cppio();

	cin >> n;
	rrep(i, n){
		cin >> s[i]; t[i] = s[i];
		for(int j=1; j<=AL; ++j){
			for(int k=0; k+j-1 < s[i].length(); ++k){
				int v = 0;
				for(int l=0; l<j; ++l)
					v = v*2 + (s[i][k+l]-'0');
				chk[i][(1<<j) + v] = 1;
			}
		}
	}

	int m; cin >> m;
	for(int mi=n+1; mi<=n+m; ++mi){
		int ia, ib; cin >> ia >> ib;
		t[mi] = (t[ia] + t[ib]);
		if(t[mi].length() > AL)
			t[mi] = t[mi].substr(t[mi].length() - AL);
		s[mi] = (s[ia] + s[ib]).substr(0, AL);

		chk[mi] = chk[ia] | chk[ib];
		auto mid = t[ia] + s[ib];
		for(int j=0; j<t[ia].length(); ++j){
			for(int k=t[ia].length()+1-j; k<=AL && j+k-1<mid.length(); ++k){
				int v = 0;
				for(int l=0; l<k; ++l)
					v = v*2 + (mid[j+l]-'0');
				chk[mi][(1<<k) + v] = 1;
			}
		}

		for(int k=AL; 0<=k; --k){
			bool ok = 1;
			int m = (1<<k);
			for(int j=0; j<m; ++j){
				if(!chk[mi][m+j]){
					ok = 0; break;
				}
			}
			if(!k || ok){
				cout << k << '\n';
				break;
			}
		}
	}

	return 0;
}