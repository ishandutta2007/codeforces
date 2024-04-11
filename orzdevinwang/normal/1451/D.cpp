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
int n, k;
void Main() {
	scanf("%d%d", &n, &k);
	int i = 0; while(2ll * i * i <= 1ll * n * n) i += k;
	i -= k;
	if(1ll * i * i + 1ll * (i + k) * (i + k) <= 1ll * n * n) puts("Ashish");
	else puts("Utkarsh");
}
int main() {
	int T; scanf("%d", &T);
	while(T--) Main();
	return 0;
}