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
	int n;
	cin >> n;
	ld xi[n];
	for(int i = 0;i<n;i++)
		cin >> xi[i];
	ld sp[n];
	for(int j = 0;j<n;j++)
		cin >> sp[j];
	ld l = 0;
	ld r = (ld)2e9 + 9;
	bool can;
	ld li = -4e9;
	ld ri = 4e9;
	ld mi;
	for(int it = 0;it<=150;it++){
		mi = (l+r)/2;
		li = -4e9;
		ri = 4e9;
		for(int i = 0;i<n;i++){
			li = max(xi[i]-mi*sp[i],li);
			ri = min(xi[i]+mi*sp[i],ri);
		}
		if(ri>=li)
			r = mi;
		else
			l = mi;
	}
	cout << fixed << setprecision(7) << r << "\n";
	return 0;
}