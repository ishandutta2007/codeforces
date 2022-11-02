#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e15 + 7;
const int max_n = 1e5 + 1;

vector<int> a;
set<int> temp;


void add() {
	int num1 = 1;
	while(temp.find(num1) != temp.end()) num1++;
	int num2 = num1 + 1;
	while(temp.find(num2) != temp.end() || temp.find(num1 ^ num2) != temp.end()) {
		num2++;
	}

	a.emplace_back(num1);
	a.emplace_back(num2);
	a.emplace_back(num1 ^ num2);
	temp.emplace(num1);
	temp.emplace(num2);
	temp.emplace(num1 ^ num2);
}




int qqq = 0;

int rec(int a) {
	qqq++;
	//cout << a << '\n';
	//if (qqq == 100) return 0;
	if (a == 0) return 0;

	int bit = 0;
	while(a >= (1LL << (bit + 1))) bit++;

	if (bit % 2 == 0) bit++; 

	int q1 = (a & (1LL << bit));
	int q2 = (a & (1LL << (bit - 1)));

	if (q1 == 0) return (1LL << bit) + rec(a - q1 - q2);
	if (q2 == 0) return (1LL << (bit - 1)) + q1 + rec(a - q1 - q2);
	return q2 + rec(a - q1 - q2);
}


int num1(int n) {
	n--;
	n /= 3;
	int bit = 0;
	while((1LL << bit) <= n) {
		n -= (1LL << bit);
		bit += 2;
	}

	return (1LL << bit) + n;
}

void solve() {
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;
		int n1 = num1(n);
		int n2 = rec(n1);
		int n3 = (n1 ^ n2);

		if (n % 3 == 1) cout << n1 << '\n';
		else if (n % 3 == 2) cout << n2 << '\n';
		else cout << n3 << '\n';

		//cout << n1 << " " << n2 << " " << n3 << '\n';
	}
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);

   /*	for(int i = 0;i < 10;i++) add();
   	for(int i : a) cout << i << " ";
   	cout << '\n';*/

   	solve();
}