#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;


int sz[N];
bool is[N];

int main(){
	fastIO;
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> a;
	vector<pii> b;
	ll x;
	ll answ = 0;
	for(int i = 0 ; i < n; i ++ ){
		cin >> x;
		answ += x;
		a.push_back(x);
		b.push_back(mp(x, i));
	}
	sort(b.begin(), b.end());
	sort(a.begin(), a.end());
	int bad = n - m * k;
	for(int i = 0 ;i < bad; i ++ ){
		is[b[i].se] = true;
		answ -= b[i].fi;
	}
	cout << answ << "\n";
	int r = m;
	vector<int>  ends;
	for(int i = 0 ;i  < n ; i ++ ){
		if(!is[i]){
			r -- ;
			if(r == 0){
				ends.push_back(i+1);
				r = m;
			}
		}
	}
	for(int j = 0; j < k-1; j ++ )
		cout << ends[j] << " ";
	return 0;
}