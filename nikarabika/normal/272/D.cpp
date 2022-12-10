#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, LL> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 2e5 + 85 - 69;
pie a[maxn];
LL D;
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n * 2; i++){
		cin >> a[i].L;
		a[i].R = ((i < n) ? i + 1 : i - n + 1);
	}
	n *= 2;
	cin >> D;
	sort(a, a + n);
	int c = 0;
	for(int i = 0; i < n - 1; i++)
		c += (a[i] == a[i + 1]);
	LL ans = 1;
	for(LL i = 0; i < n;){
		int p = i + 1;
		while(p < n and a[p].L == a[p - 1].L){
			if(c and (p - i + 1) % 2 == 0)
				ans = (ans * ((p - i + 1) / 2)) % D, c--;
			else
				ans = (ans * (p - i + 1)) % D;
			p++;
		}
		i = p;
	}
	cout << ans << endl;
	return 0;
}