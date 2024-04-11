#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 1e5 + 100;
int like[maxn];
int ss[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	s += ' ';
	rep(i, s.size()-1){
        if(s[i] == s[i + 1])
            like[i] = 1;
        ss[i + 1] = ss[i] + like[i];
	}
	/*rep(i, s.size())
        cout << ss[i] << ' ';
    cout << endl;*/
	int m;
	cin >> m;
	rep(i, m){
        int l, r;
        cin >> l >> r;
        cout << ss[r - 1] - ss[l - 1] << endl;
	}
	return 0;
}