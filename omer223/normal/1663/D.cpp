#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <string>
#include <queue>
#include <time.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef pair<ld, ld> pld;


bool isnum(char c) {
	return (c >= '0' && c <= '9');
}


int foo() {
	return 0;
}

int main() {
	fast;
	srand(time(NULL));
	string s;
	ll x;
	cin >> s >> x; //s = "ABC", x = 1e9 => YES
	if (s == "ABC") {
		if (x >= 0 && x <= 1999)cout << "YES\n";
		else cout << "NO\n";
	}
	else if (s == "ARC") {
		if (x >= 0 && x <= 2799)cout << "YES\n";
		else cout << "NO\n";
	}
	else {
		if (x >= 1200)cout << "YES\n";
		else cout << "NO\n";
	}
	/*
	bool salpha = 0;
	salpha |= (s[2] == 'C');
	if (salpha) {
		int sum = 1;
		sum += (x > 1e9);
		x += x / (sum - 1);
	}
	cout << 3;
	*/
	return 0;
}