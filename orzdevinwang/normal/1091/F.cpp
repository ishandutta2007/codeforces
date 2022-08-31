#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, fis1, fis2;
ll f[N], sum, ans;
char s[N];
stack<int> q1, q2;
// prefer q2 to q1
void twork() {
	L(i, 1, n) {
		if(s[i] == 'G') q1.push(i);
		else if(s[i] == 'W') q2.push(i);
		else {
			while(!q2.empty() && f[i]) {
				if(f[q2.top()] > f[i]) ans += f[i] * 4, f[q2.top()] -= f[i], f[i] = 0;
				else ans += f[q2.top()] * 4, f[i] -= f[q2.top()], f[q2.top()] = 0, q2.pop();
			}
			while(!q1.empty() && f[i]) {
				if(f[q1.top()] > f[i]) ans += f[i] * 6, f[q1.top()] -= f[i], f[i] = 0;
				else ans += f[q1.top()] * 6, f[i] -= f[q1.top()], f[q1.top()] = 0, q1.pop();
			}
			assert(!f[i]);
		}
	}
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
}
void Main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%lld", &f[i]);
	scanf("%s", s + 1);
	L(i, 1, n) {
		if(s[i] == 'G') {
			if(!fis1) fis1 = i;
			sum += f[i];
		}
		else if(s[i] == 'W') {
			if(!fis2) fis2 = i;
			sum += f[i];
		}
		else {
			if(sum < f[i]) {
				if(fis2) f[fis2] += f[i] - sum;
				else f[fis1] += f[i] - sum;
				sum = f[i];
			}
			sum -= f[i];
		}
	}
	twork(); 
	//  L 
	L(i, 1, n) {
		if(s[i] == 'W') q2.push(i);
		else if(s[i] == 'G') {
			while(!q2.empty() && f[i]) {
				if(f[i] > f[q2.top()]) ans += 4 * f[q2.top()], f[i] -= f[q2.top()], f[q2.top()] = 0, q2.pop();
				else ans += 4 * f[i], f[q2.top()] -= f[i], f[i] = 0;
			}
			ans += 3 * f[i], f[i] = 0;
		}
	}
	//  George1123 
	L(i, 1, n) if(s[i] == 'W') ans += 2 * f[i];
	//  W 
	printf("%lld\n", ans);
}
int main() {
	Main();
	return 0;
}