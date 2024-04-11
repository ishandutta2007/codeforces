//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

map<string, int> mp;
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	mp["void"] = 1;
	for(int i = 0; i < n; i++){
		string ty, fi, se;
		cin >> ty;
		if(ty[4] == 'd'){
			cin >> fi >> se;
			int c1 = count(all(fi), '&'),
				c2 = count(all(fi), '*');
			string A = fi.substr(c1, sz(fi) - c1 - c2);
			int val = mp[A];
			if(val == 0)
				mp[se] = 0;
			else
				mp[se] = max(0, val + c2 - c1);
		}
		else{
			cin >> fi;
			int c1 = count(all(fi), '&'),
				c2 = count(all(fi), '*');
			string A = fi.substr(c1, sz(fi) - c1 - c2);
			int val = mp[A];
			if(val == 0 or val + c2 - c1 <= 0)
				cout << "errtype\n";
			else{
				cout << "void";
				for(int i = 1; i < val + c2 - c1; i++)
					cout << '*';
				cout << '\n';
			}
		}
	}
	return 0;
}