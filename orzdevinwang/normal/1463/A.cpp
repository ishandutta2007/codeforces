#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db long double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 505;
int T, a, b, c;
void Main() {
	scanf("%d%d%d", &a, &b, &c);
	if((a + b + c) % 9) puts("No");
	else {
		int cs = (a + b + c) / 9;
		if(a < cs || b < cs || c < cs) puts("No");
		else puts("Yes");
	}
}
int main() {
	scanf("%d", &T); while(T--) Main();
	return 0;
}