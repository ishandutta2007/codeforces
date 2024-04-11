#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 1919810;
int n, h;
mt19937 orz(time(0) ^ clock());
int query (int x, int y, int w) {
	cout << "? " << x << ' ' << y << ' ' << w << endl;
	int t;
	cin >> t;
	return t;
}
int arr[N], ord[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> h;
	n = (1 << h) - 1;
	L(i, 1, 400) {
		int x = orz() % n + 1, y = orz() % n + 1, w = orz() % n + 1;
		while (y == x) y = orz() % n + 1;
		while (w == x || w == y) w = orz() % n + 1;
		arr[query (x, y, w)] += 1;
	}
	L(i, 1, n) ord[i] = i;
	sort(ord + 1, ord + n + 1, [&] (int x, int y) {
		return arr[x] > arr[y];
	});
	int a = ord[1], b = ord[2];
	L(i, 1, n) if(i != a && i != b && query (a, b, i) == i) 
		return cout << "! " << i << endl, 0; 
	return 0;
}