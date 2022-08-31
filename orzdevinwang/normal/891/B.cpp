#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 4e6 + 7;
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f; 
}
int n, g[N];
struct node {
	int id, val; 
} a[N];
void Main() {
	n = read();
	L(i, 1, n) a[i].val = read(), a[i].id = i;
	sort(a + 1, a + n + 1, [&](node aa, node bb) {
		return aa.val < bb.val;
	});
	L(i, 1, n) g[a[i % n + 1].id] = a[i].val;
	L(i, 1, n) cout << g[i] << " ";
	cout << endl;
}
int main() {
	Main();
	return 0;
}