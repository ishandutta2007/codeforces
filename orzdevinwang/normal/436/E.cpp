/*
orz George1123 !!! 
*/
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 3e5 + 7;
int n, m, a[N << 1];
bool vis[N << 1];
priority_queue< pii > q1, q2;
void fix() {
	while(!q1.empty() && vis[q1.top().second]) q1.pop();//, cout << "qwq\n";
	while(!q2.empty() && vis[q2.top().second]) q2.pop();//, cout << "awa\n";
}
ll sum;
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, n) scanf("%d%d", &a[i], &a[i + n]), q1.push(mkp(-a[i], i)), q2.push(mkp(-a[i + n], i)), a[i + n] -= a[i];
	while(m--) {
//		cout << m << endl;
		fix(); int now = q1.top().second; q1.pop(); fix();
		if(m && !q2.empty() && a[now] - q1.top().first > - q2.top().first) 
			q1.push(mkp(-a[now], now)), now = q2.top().second, q2.pop();
		sum += a[now], vis[now] = 1;
		if(now <= n) q1.push(mkp(-a[now + n], now + n));
	} 
	printf("%lld\n", sum);
	L(i, 1, n) printf("%d", vis[i] + vis[i + n]);
	puts("");
	return 0;
}