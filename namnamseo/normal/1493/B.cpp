#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

#define ref Reflect

const int maxn = int(2e5) + 10;

int n;

int ref[10] = {
	0, 1, 5, -1, -1,
	2, -1, -1, 8, -1
};

int main()
{
	cppio();
	int tc; cin >> tc;
	cout << setfill('0');

rep(tci, tc) {
	int ah, am; string s;
	cin >> ah >> am >> s;
	int ch = (s[0]-'0')*10 + (s[1]-'0');
	int cm = (s[3]-'0')*10 + (s[4]-'0');

	int rh, rm;
	while (true) {
		bool ok = 1;
		if (ref[ch%10] == -1 || ref[ch/10] == -1) ok = 0;
		if (ref[cm%10] == -1 || ref[cm/10] == -1) ok = 0;
		if (ok) {
			rm = ref[ch%10] * 10 + ref[ch/10];
			rh = ref[cm%10] * 10 + ref[cm/10];
			if (rh < ah && rm < am){
				break;
			}
		}
		++cm;
		if (cm == am) {
			cm = 0;
			++ch;
			if (ch == ah) {
				ch = 0;
			}
		}
	}

	cout << setw(2) << ch << ':' << setw(2) << cm << '\n';
}


	return 0;
}