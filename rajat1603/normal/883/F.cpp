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

const int maxn = 440;
//const int md = 1e9 + 7;

string s[maxn];

string reduce(string s) {

	//cout<<" >> "<<s<<endl;

	string t = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'u') {
			t += "oo";
			for (int j = i + 1; j < s.size(); j++) {
				t += s[j];
			}
			return reduce(t);
		}
		if (s[i] == 'k' && i + 1 < s.size() && s[i+1] == 'h') {
			t += 'h';

			for (int j = i + 2; j < s.size(); j++) {
				t += s[j];
			}

			return reduce(t);
		}

		t += s[i];
	}

	return s;
}

int main() {
	IOS;
	int n; cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>s[i];
		s[i] = reduce(s[i]);
		//cout<<s[i]<<endl;
	}

	sort(s+1,s+n+1);

	int grp = 0; s[0] = "";

	for (int i = 1; i <= n; i++) {
		
		//cout<<s[i]<<endl;

		if (s[i] != s[i-1]) {
			grp++;
		}
	}

	cout<<grp<<endl;
}