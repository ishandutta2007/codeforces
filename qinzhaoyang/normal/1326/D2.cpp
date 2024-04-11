#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 1e6 + 10;

namespace HASH {
	int MOD1 = 1004535809 , MOD2 = 167772161;
	int h_s1[N], h_s2[N], h_v1[N], h_v2[N];

	int h_add(int x , int y , int MOD) {return x + y >= MOD ? x + y - MOD : x + y;}
	int h_sub(int x , int y , int MOD) {return x < y ? x + MOD - y : x - y;}
	int h_mul(int x , int y , int MOD) {return 1ll * x * y % MOD;} 
	int h_Pow(int x , int y , int MOD) {int ret = 1;while(y){if(y & 1)ret = h_mul(ret , x , MOD);x = h_mul(x , x , MOD) , y >>= 1;}return ret;}
	
	class Hash {
	public:
		int f , s;
		Hash(int f = 0, int s = 0) : f(f), s(s) {}
		inline friend Hash operator + (Hash H1, Hash H2) {return (Hash){h_add(H1.f, H2.f, MOD1) , h_add(H1.s, H2.s, MOD2)};}
		inline friend Hash operator - (Hash H1, Hash H2) {return (Hash){h_sub(H1.f, H2.f, MOD1) , h_sub(H1.s, H2.s, MOD2)};}
		inline friend Hash operator * (Hash H1, Hash H2) {return (Hash){h_mul(H1.f, H2.f, MOD1) , h_mul(H1.s, H2.s, MOD2)};}
		inline friend int operator == (Hash H1, Hash H2) {return (H1.f == H2.f) && (H1.s == H2.s);}
		inline friend int operator != (Hash H1, Hash H2) {return (H1.f != H2.f) || (H1.s != H2.s);}
		inline friend Hash operator << (Hash H1, int t) {return (Hash){h_mul(H1.f, h_s1[t], MOD1) , h_mul(H1.s, h_s2[t], MOD2)};}
		inline friend Hash operator >> (Hash H1, int t) {return (Hash){h_mul(H1.f, h_v1[t], MOD1) , h_mul(H1.s, h_v2[t], MOD2)};}
		inline friend int operator < (Hash H1, Hash H2) {return H1.f == H2.f ? H1.s < H2.s : H1.f < H2.f;}
	};

	void init(int n) {
		h_s1[0] = h_s2[0] = 1;
		h_s1[1] = 233 , h_s2[1] = 239;
		for(int i = 2; i <= n; i++) h_s1[i] = h_mul(h_s1[i - 1] , h_s1[1] , MOD1);
		for(int i = 2; i <= n; i++) h_s2[i] = h_mul(h_s2[i - 1] , h_s2[1] , MOD2);
		for(int i = 0; i <= n; i++) h_v1[i] = h_Pow(h_s1[i] , MOD1 - 2 , MOD1);
		for(int i = 0; i <= n; i++) h_v2[i] = h_Pow(h_s2[i] , MOD2 - 2 , MOD2);
	}

	Hash mk_c(char c) {return Hash(c, c);}
	Hash mk_s(char *s) {
		int len = strlen(s); Hash ret(0, 0);
		for(int i = 0; i < len; i++) ret = (ret << 1) + mk_c(s[i]);
		return ret;
	}
	Hash mk_s(string s) {
		Hash ret(0, 0);
		for(int i = 0; i < s.size(); i++) ret = (ret << 1) + mk_c(s[i]);
		return ret;
	}
};
using namespace HASH;

int T, n;
char s[N];
Hash pre[N], suf[N];

Hash sublr(int l, int r) {
	if (l > r) return Hash();
	return pre[r] - (pre[l - 1] << (r - l + 1));
}

Hash subrl(int l, int r) {
	if (l > r) return Hash();
	return suf[l] - (suf[r + 1] << (r - l + 1));
}

int main() {
	init(1000000);
	for (read(T); T; T--) {
		scanf("%s", s + 1), n = strlen(s + 1);
		int c1 = 0, c2 = n + 1, l, r;
		while (c1 + 1 < c2 - 1 && s[c1 + 1] == s[c2 - 1]) c1++, c2--;
		pre[n + 1] = pre[0] = suf[n + 1] = suf[0] = Hash();
		for (int i = 1; i <= n; i++) pre[i] = (pre[i - 1] << 1) + mk_c(s[i]);
		for (int i = n; i >= 1; i--) suf[i] = (suf[i + 1] << 1) + mk_c(s[i]);
		int ans = c1 * 2; l = c1 + 1, r = c2 - 1;
		for (int i = c1 + 1; i <= c2 - 1; i++) {
			int len1 = i - (c1 + 1), len2 = (c2 - 1) - i;
			if (len1 < len2) {
				if (sublr(c1 + 1, i - 1) == subrl(i + 1, i + len1)) {
					if (1 + len1 * 2 + c1 * 2 > ans) {
						ans = max(ans, 1 + len1 * 2 + c1 * 2);
						l = i + len1 + 1, r = c2 - 1;
					}
				}
			}
			else {
				if (sublr(i - len2, i - 1) == subrl(i + 1, c2 - 1)) {
					if (1 + len2 * 2 + c1 * 2 > ans) {
						ans = max(ans, 1 + len2 * 2 + c1 * 2);
						l = c1 + 1, r = i - len2 - 1;
					}
				}
			}
		}
		for (int i = c1 + 1; i <= c2 - 2; i++) {
			int len1 = i - c1, len2 = (c2 - 1) - i;
			if (len1 < len2) {
				if (sublr(c1 + 1, i) == subrl(i + 1, i + len1)) {
					if (len1 * 2 + c1 * 2 > ans) {
						ans = max(ans, len1 * 2 + c1 * 2);
						l = i + len1 + 1, r = c2 - 1;
					}
				}
			}
			else {
				if (sublr(i - len2 + 1, i) == subrl(i + 1, c2 - 1)) {
					if (len2 * 2 + c1 * 2 > ans) {
						ans = max(ans, len2 * 2 + c1 * 2);
						l = c1 + 1, r = i - len2;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++)
			if (!(l <= i && i <= r))
				printf("%c", s[i]);
		puts("");
	}
	return 0;
}