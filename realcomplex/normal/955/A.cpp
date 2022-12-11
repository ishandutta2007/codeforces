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
	int h,m;
	cin >> h >> m;
	int ch,dh,dec;
	ld c;
	cin >> ch >> dh >> c >> dec;
	ld r = c * 0.8;
	ld hung = 0;
	ld ans = (ld)2e9;
	ld cur = 0;
	ld nt = 0,rk = 0;
	int req;
	for(int i = 0;i<10000;i++){
		if(h < 20)
			nt++;
		else
			rk++;
		req = (ch + dec - 1) / dec;
		if(rk != 0)
			cur = req * r;
		else
			cur = req * c;
		ans = min(ans,cur);
		ch += dh;
		m++;
		if(m >= 60)
			h++,m = 0;
		if(h >= 24)
			h = 0;
	}
	cout << fixed << setprecision(6) << ans << "\n";
	return 0;
}