#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pd(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define sf(n) scanf("%f",&n)
#define pf(n) printf("%.12f",n)
#define psp printf(" ")
#define endc printf("\n")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 2000;
//const int md = 1e9 + 7;

string z[maxn];
vector<int> pos;
bool shown[maxn];
bool ins[maxn];
bool cur[maxn];

int main() {
	IOS;
	int n; cin>>n;
	string s; cin>>s;
	
	for (int i = 0; i < n; i++) {
		if (s[i] != '*') shown[s[i]] = true;
	}
	int m;
	cin>>m; fill(ins, ins+maxn, 1);
	for (int i = 1; i <= m; i++) {
		bool elim = false;
		cin>>z[i];
		
		for (int j = 0; j < n; j++) {
			if (s[j] != '*') {
				if (s[j] != z[i][j]) {elim = true; break;}
				continue;
			}
			if (shown[z[i][j]]) { elim = true; break; }
		}

		if (elim) continue;
		
		fill(cur, cur+maxn, 0);

		//cout<<z[i]<<"ok"<<endl;

		for (int j = 0; j < n; j++) {
			if (s[j] != '*') continue;
			cur[z[i][j]] = 1;
		}

		for (int j = 0; j < maxn; j++) ins[j] &= cur[j];
	}

	int ans = 0;
	for (int i = 0; i < maxn; i++) ans += ins[i];

	cout<<ans<<endl;
}