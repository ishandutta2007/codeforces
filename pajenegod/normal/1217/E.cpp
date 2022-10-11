//https://codeforces.com/contest/1217/submission/60126579
#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC target ("sse4")
#pragma GCC target ("avx,tune=native")
//Use above if bruteforcing with lots of small operations. Or just use it anytime, there's no downside. AVX is better slightly
/*
by farmersrice
*/
using namespace std;
typedef long long ll;
typedef pair<int, int> pair2;
typedef pair<int, pair<int, int> > pair3;
typedef pair<int, pair<int, pair<int, int> > > pair4;
#define MAXN 200013
#define INF 1000000000000000000LL
#define MOD 1000000007LL
#define IINF 1000000000
#define mp make_pair
#define pb push_back
#define remove pop
#define all(x) x.begin(), x.end()
 
//Find two smallest numbers with differing nonzero digits at any position
int n, m;
int outerValues[MAXN];
 
int helper[4];
struct SegtreeMax {
	pair2 *values;
	int length;
 
 	SegtreeMax(){}
 
	SegtreeMax(int len) {
		length = len;
 
 		values = new pair2[4 * len];
		for (int i = 0; i < 4 * len; i++) {
			values[i] = mp(IINF, IINF);
		}
	}
 
	void update(int index, int value, int i = 1, int left = 0, int right = MAXN - 1) {
		if (right < index || index < left || right < left) return;
 
		if (left == right) {
			values[i] = mp(value, IINF);
			//cout << "set value " << endl;
			return;
		}
 
		int mid = (left + right) / 2;
 
		update(index, value, 2 * i, left, mid);
		update(index, value, 2 * i + 1, mid + 1, right);
 
		//UPDATE STAGE:
		int v1 = values[2 * i].first;
		int v2 = values[2 * i].second;
		int v3 = values[2 * i + 1].first;
		int v4 = values[2 * i + 1].second;
 
		helper[0] = v1; helper[1] = v2; helper[2] = v3; helper[3] = v4;
 
		int best = IINF;
		int bestIndex = -1;
		for (int i = 0; i < 4; i++) {
			if (helper[i] < best) {
				best = helper[i];
				bestIndex = i;
			}
		}
 
		int temp2 = IINF;
		for (int i = 0; i < 4; i++) {
			if (bestIndex == i) continue;
			temp2 = min(temp2, helper[i]);//values[i].second = min(values[i].second, helper[i]);
			//cout << "got " << helper[i] << endl;
		}
 
		values[i] = mp(best, temp2);
 
		//cout << "had ";
		//for (int i = 0; i < 4; i++) {
		//	cout << helper[i] << ' ';
		//}
		//cout << endl;
		//cout << "bestIndex is " << bestIndex << endl;
 
		//cout << "values " << i << " is now " << values[i].first << ' ' << values[i].second << endl;
		//values[i] = max(values[2 * i], values[2 * i + 1]);
	}
 
	pair2 query(int start, int end, int i, int left, int right) {
		if (right < start || end < left || right < left) return mp(IINF, IINF);
 
		if (start <= left && right <= end) {
			return values[i];
		}
 
		int mid = (left + right) / 2;
 
		pair2 p1 = query(start, end, 2 * i, left, mid);
		pair2 p2 = query(start, end, 2 * i + 1, mid + 1, right);
 
		//UPDATE STAGE:
		int v1 = p1.first;
		int v2 = p1.second;
		int v3 = p2.first;
		int v4 = p2.second;
 
		helper[0] = v1; helper[1] = v2; helper[2] = v3; helper[3] = v4;
 
		int best = IINF;
		int bestIndex = -1;
		for (int i = 0; i < 4; i++) {
			if (helper[i] < best) {
				best = helper[i];
				bestIndex = i;
			}
		}
 
		int temp2 = IINF;
		for (int i = 0; i < 4; i++) {
			if (bestIndex == i) continue;
			temp2 = min(temp2, helper[i]);//answer.second = min(answer.second, helper[i]);
		}
		return mp(best, temp2);
	}
};
 
SegtreeMax digits[10];
 
int main() {
	if (fopen("FILENAME.in", "r")) {
		freopen("FILENAME.in", "r", stdin);
		freopen("FILENAME.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
 
	int n, m; 
	cin >> n >> m;
 
	for (int i = 0; i < 9; i++) {
		digits[i] = SegtreeMax(n);
	}
 
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
 
		int original = v;
		int power = 100000000;
		for (int j = 0; j < 9; j++) {
			if (v / power > 0) {
				digits[j].update(i, original, 1, 0, n - 1);
				//cout << "updating " << j << " at " << i << " with " << original << endl;
				v %= power;
			}
			power /= 10;
		}
 
		outerValues[i] = original;
	}
 
	while (m--) {
		int option;
		cin >> option;
 
		if (option == 1) {
			int i, x;
			cin >> i >> x;
			i--;
			//Replace a[i] with value x
 
			int v = outerValues[i];
			int power = 100000000;
			for (int j = 0; j < 9; j++) {
				if (v / power > 0) {
					digits[j].update(i, IINF, 1, 0, n - 1);
					v %= power;
				}
				power /= 10;
			}
 
			v = x;
			power = 100000000;
			for (int j = 0; j < 9; j++) {
				if (v / power > 0) {
					digits[j].update(i, x, 1, 0, n - 1);
					v %= power;
				}
				power /= 10;
			}
 
			outerValues[i] = x;
		} else {
			int l, r;
			cin >> l >> r;
			l--;r--;
 
			int answer = 2 * IINF + 1;
 
			for (int j = 0; j < 9; j++) {
				pair2 p = digits[j].query(l, r, 1, 0, n - 1);
				if (p.first == IINF || p.second == IINF) continue;
				answer = min(answer, p.first + p.second);
				//cout << "have answer as " << answer << endl;
			}
			cout << (answer >= (2 * IINF + 1) ? -1 : answer) << '\n';
		}
	}
}
 
//don't do dumb stuff with merge-sort tree like using update when everything is static...
 
//IF IT'S MATH THE ANSWER IS IN THE GCD, GCD THE INPUTS, OR WHATEVER USE GCD
//CAST .SIZE() TO INT!!!!
 
//PRO TIP: THE BEST WAY TO SOLVE THE PROBLEM IS TO HAVE THE RIGHT ANSWER!