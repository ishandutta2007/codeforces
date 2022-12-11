#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))

int main(){
	fastIO;
	ll x,d;
	cin >> x >> d;
	ll l = 1;
	vector<ll>rez;
	ll p = (ll)1e15;
	for(int i = 0;i<32;i++){
		if(x & (1LL << i)){
			for(int v = 0;v<i;v++)
				rez.push_back(l);
			rez.push_back(p);
			p+=d+9; 
			l += d+9;
		}
	}
	cout << rez.size() << "\n";
	for(auto x : rez)
		cout << x << " ";
	cout << "\n";
	return 0;
}