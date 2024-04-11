#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 2e5;

int len;
char s[MAXN];
int num[MAXN];
int res[MAXN];

pii get_any_pair(int sum) {
 	if (sum == 0) {
 	 	return {0, 0};
 	}
 	if (sum <= 10) {
 	 	return {1, sum - 1};
 	}
 	return {9, sum - 9};
}

int print_ans() {
	if (!res[len - 1]) {
	 	return 0;
	}
	for (int i = len - 1; i >= 0; --i) {
 	 	cout << res[i]; 	 	
 	}
 	cout << "\n";
 	exit(0);
}

int try_parse(int l, int r) {
	/*
	cerr << l << " " << r << endl;
	for (int i = l; i <= r; ++i) {
	 	cerr << num[i] << " ";
	}
	cerr << endl;*/
	if (l == r) {
	 	if (num[l] & 1) {
	 	 	return 0;
	 	}
	 	res[l] = num[l] / 2;
	 	print_ans();
	 	return 0;
	}
	if (l > r) {
	 	print_ans();
	 	return 0;
	}
 	bool flag = false;
	if (num[l] == -1) {
	 	num[l] += 10;
	 	num[l + 1] -= 1;
	 	flag = true;
	}	
 	if (num[l] == num[r]) {
 	 	pii p = get_any_pair(num[l]);
 	 	res[l] = p.ss;
 	 	res[r] = p.ff;
 	 	try_parse(l + 1, r - 1);
 	} else {
 	 	if (num[r] == num[l] + 1 && r > l + 1) {
 	 		pii p = get_any_pair(num[l]);
 	 	 	res[l] = p.ss;
 	 	 	res[r] = p.ff;
			num[r - 1] += 10;
			if (l + 1 < r - 1 && num[l + 1] != 9) {
			 	num[l + 1] += 10;
			 	num[l + 2] -= 1;			 	
			}
			try_parse(l + 1, r - 1);
			num[r - 1] -= 10;
			if (l + 1 < r - 1 && num[l + 1] != 9) {
			 	num[l + 1] -= 10;
			 	num[l + 2] += 1;			 	
			}
 	 	}
 	}
 	if (flag) {
	 	num[l] -= 10;
	 	num[l + 1] += 1;
	}
	
 	return 0;
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%s", s);
	len = strlen(s);
	for (int i = 0; i < len; ++i) {
	 	num[i] = s[i] - '0';
	}

	reverse(num, num + len);

	try_parse(0, len - 1);

	if (num[len - 1] == 1 && len > 1) {
	 	num[len - 2] += 10;
	 	if (0 < len - 2 && num[0] != 9) {
	 	 	num[0] += 10;
	 	 	num[1] -= 1;	 	 	
	 	}
	 	--len;
	 	try_parse(0, len - 1);
	 	++len;
	 	num[len - 2] -= 10;
	 	if (0 < len - 2 && num[0] != 9) {
	 	 	num[0] -= 10;
	 	 	num[1] += 1;	 	 
	 	}	 		 	
	}
	/*
	if (num[len - 1] == 1 && num[0] == 9 && len > 1) {
	 	num[len - 2] += 10;
	 	--len;
	 	try_parse(0, len - 1);
	 	++len;
	 	num[len - 2] -= 10;	 		 		 	
	}*/

	cout << 0 << "\n";

	return 0;
}