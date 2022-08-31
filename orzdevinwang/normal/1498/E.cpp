#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define ull unsigned long long
#define sz(a) ((int) (a).size())
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7;
int m, n, ns1, ns2, ns = -1;
struct node {
	int id, w;
} a[N];
void Main() {
	cin >> n;
	L(i, 1, n) cin >> a[i].w, a[i].w = n - a[i].w - 1, a[i].id = i; 
	sort(a + 1, a + n + 1, [&] (node aa, node bb) { return aa.w < bb.w; });
	int las = 1, sum = 0;
	L(i, 1, n) {
		sum += a[i].w;
		if(las != i && a[i].w - a[las].w > ns) 
			ns = a[i].w - a[las].w, ns1 = a[i].id, ns2 = a[las].id;
		if(sum == i * (i - 1) / 2) las = i + 1;
	}
	cout << "! " << ns1 << " " << ns2 << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main();
	return 0;
}