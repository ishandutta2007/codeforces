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

const int maxn = 300; 
//const int md = 1e9 + 7;

int occ[maxn];
vector<string> v;
vector<string> a;

int main() {
	IOS;
	int n; cin>>n;
	string s; cin>>s;	

	for (int i = 0; i < n; i++) {
		occ[s[i]]++;
	}
	
	v.clear();

	for (int i = 0; i < maxn; i++) {
		if (occ[i] % 2 == 0) continue;
		v.pb(""); occ[i]--; a.pb("");
		v[v.size()-1] += (char)i;
	}
	
	if (v.size() == 0) {
		string s = "";
		for (int i = 0; i < maxn; i++) {
			for (int j = 0; j< occ[i]/2; j++) {
				s += (char)i;
			}
		}
		cout<<1<<endl;
		cout<<s;
		reverse(s.begin(), s.end());
		cout<<s<<endl;
		return 0;
	}
		
	int k = v.size();

	int z = k;
	while (n%z != 0 || ((n/z) % 2 == 0)) z++;

	for (int i = 0; i < maxn; i++) {
		while (occ[i] > 0 && v.size() < z) { v.pb(""); v[v.size()-1] += (char)i; occ[i]--; a.pb(""); }
	}

	int pos = 0;
	for (int i = 0; i < maxn; i++) {
		while (occ[i] > 0) {
			a[pos] += (char)i; occ[i] -= 2;
			pos++; if (pos >= z) pos = 0;
		}
	}
	cout<<z<<endl;
	for (int i = 0; i < z; i++) {
		cout<<a[i]<<v[i];
		reverse(a[i].begin(), a[i].end());
		cout<<a[i]<<" ";
	}
	cout<<endl;

	return 0;
}