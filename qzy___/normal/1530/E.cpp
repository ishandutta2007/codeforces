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

const int N = 1e5 + 10;

int T, n, c[26]; char s[N];

int findnxt(int i) {
	while (i != 26 && c[i] == 0) i++;
	return i;
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> T; T; T--) {
		cin >> s + 1; n = strlen(s + 1);
		for (int i = 0; i < 26; i++) c[i] = 0;
		for (int i = 1; i <= n; i++)
			c[s[i] - 'a']++;
		int flag = 0;
		for (int i = 0; i < 26; i++) {
			if (c[i] == 1) {
				cout << char(i + 'a'), c[i]--;
				for (int j = 0; j < 26; j++)
					for (int k = 1; k <= c[j]; k++)
						cout << char(j + 'a');
				cout << endl;
				flag = 1;
				break;
			}
		}
		if (flag) continue;
		int minc = -1, mic = -1;
		for (int i = 0; i < 26; i++) {
			if (c[i] != 0) {
				if (minc == -1) minc = i;
				else if (minc != -1 && mic == -1) mic = i;
			}
		}
		if (c[minc] > 1) {
			int cp = n - c[minc];
			if (cp >= c[minc] - 2) {
				cout << char(minc + 'a') << char(minc + 'a');
				c[minc] -= 2;
				for (int i = 1; i <= c[minc]; i++) {
					mic = findnxt(mic), c[mic]--;
					cout << char(mic + 'a') << char(minc + 'a');
				}
				while (findnxt(mic) != 26) {
					mic = findnxt(mic);
					cout << char(mic + 'a');
					c[mic]--;
				}
				cout << endl;
				flag = 1;
				continue;
			}
		}
		if (n - c[minc] - c[mic] > 0) {
			int t = -1;
			for (int i = mic + 1; i < 26; i++) {
				if (c[i] == 0) continue;
				t = i; break;
			}
			cout << char(minc + 'a') << char(mic + 'a');
			c[minc]--, c[mic]--;
			for (int i = 1; i <= c[minc]; i++)
				cout << char(minc + 'a');
			cout << char(t + 'a'), c[t]--;
			for (int i = 1; i <= c[mic]; i++)
				cout << char(mic + 'a');
			while (findnxt(t) != 26) {
					t = findnxt(t);
					cout << char(t + 'a');
					c[t]--;
			}
			cout << endl;
		}
		else {
			cout << char(minc + 'a'); c[minc]--;
			for (int i = 1; i <= c[mic]; i++)
				cout << char(mic + 'a');
			for (int i = 1; i <= c[minc]; i++)
				cout << char(minc + 'a');
			cout << endl;
		}
	}
	return 0;
}