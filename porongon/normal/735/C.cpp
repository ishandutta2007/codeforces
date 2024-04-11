#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define fore(i,a,n) for(int i = a,qwer=n;i<qwer;i++)

using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> ii;
const int N = 100500;

int main() {
	ll n;
	scanf("%lld",&n);
	int ans = 0;
	ll a = 1, b = 1,c;
	while(a+b <= n) {
		ans++;
		c = b;
		b = a + b;
		a = c;
	}
	printf("%d\n",ans);
}