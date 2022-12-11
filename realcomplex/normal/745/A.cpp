#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

int main(){
	fastIO;
	string a;
	cin >> a;
	string cur;
	set<string>u;
	for(int i = 0;i<a.size();i++){
		u.insert(a);
		cur.clear();
		cur += a[a.size()-1];
		cur += a.substr(0,a.size()-1);
		a = cur;
	}
	cout << u.size() << "\n";
	return 0;
}