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
	int n,k;
	cin >> n >> k;
	if( k <= n or n == 4){
		cout << "-1\n";
		return 0;
	}
	set<int>sk;
	for(int i = 1;i<=n;i++)
		sk.insert(i);
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	sk.erase(a);
	sk.erase(b);
	sk.erase(c);
	sk.erase(d);
	cout << a << " " << c << " ";
	for(auto x : sk)
		cout << x << " ";
	cout << d << " " << b << "\n";
	cout << c << " " << a << " ";
	for(auto x : sk)
		cout<< x << " ";
	cout << b << " " << d << "\n";
	return 0;
}