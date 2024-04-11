#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const int Z = 'z' +1;

int Cnt[N][Z];

int main ()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	rep(q,0,t) {
		int n, m;
		cin>>n >>m;
		
		rep(i,0,m) rep(j,'a','z'+1) Cnt[i][j] = 0;
		
		string s;
		rep(i,0,n) {
			cin>>s;
			rep(j,0,m) Cnt[j][s[j]]++;
		}
		
		rep(i,0,n-1) {
			cin>>s;
			rep(j,0,m) Cnt[j][s[j]]--;
		}
		
		s.clear();
		rep(i,0,m) {
			rep(j,'a','z'+1) if (Cnt[i][j]) s.pb(j);
		}
		
		cout<<s <<"\n";
		fflush(stdout);
	}	
}