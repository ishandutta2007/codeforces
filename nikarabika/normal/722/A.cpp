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

void func(int x){
	if(x < 10)
		cout << 0;
	cout << x;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int form, hh, mm;
	char ch;
	cin >> form;
	cin >> hh >> ch >> mm;
	if(form == 24){
		if(hh >= 24)
			hh = 10 + hh % 10;
		if(mm >= 60)
			mm = 10 + mm % 10;
		func(hh);
		cout << ':';
		func(mm);
		return 0;
	}
	if(hh == 0)
		hh = 10;
	else if(hh > 12)
		hh = (10 * (hh % 10 == 0)) + hh % 10;
	if(mm >= 60)
		mm = 10 + mm % 10;
	func(hh);
	cout << ':';
	func(mm);
	return 0;
}