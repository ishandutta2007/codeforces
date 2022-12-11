//sobskdrbhvk
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
#define scr SCORE

LL mnof(LL cnt, LL pos){
	LL mxcnt = cnt % pos;
	LL mn = cnt / pos;
	LL mx = mn + 1;
	return mxcnt * mx * mx + (pos - mxcnt) * mn * mn;
}

LL mxof(LL cnt, LL pos){
	cnt -= pos - 1;
	return pos - 1 + cnt * cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL a, b;
	cin >> a >> b;
	if(a == 0){
		cout << -b*b << endl;
		for(int i = 0; i < b; i++)
			cout << 'x';
		cout << endl;
		return 0;
	}
	if(b == 0){
		cout << a * a << endl;
		for(int i = 0; i < a; i++)
			cout << 'o';
		cout << endl;
		return 0;
	}
	LL scr = -85LL * 1000 * 1000 * 1000 * 1000;
	LL ans = 0;
	for(LL i = 1; i <= min(b, a); i++){
		LL val = mxof(a, i) - mnof(b, i + 1);
		if(val >= scr){
			scr = val;
			ans = i;
		}
	}
	cout << scr << '\n';
	LL cnt = b % (ans + 1);
	for(int i = 0; i < ans; i++){
		for(int j = 0; j < b / (ans+1) + bool(cnt); j++)
			cout << 'x';
		if(cnt) cnt--;
		cout << 'o';
	}
	a -= ans;
	for(int i = 0; i < a; i++)
		cout << 'o';
	for(int i = 0; i < b / (ans + 1); i++)
		cout << 'x';
	cout << endl;
	return 0;
}