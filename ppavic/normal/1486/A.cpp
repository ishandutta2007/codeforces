#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 1e5 + 500;

int n;

void solve(){
	scanf("%d", &n);
	ll sm = 0; bool ret = 1;
	for(int i = 0;i < n;i++){
		int x; scanf("%d", &x);
		sm += x;
		ret &= (2LL * sm >= (ll)(i + 1) * i);
	}
	printf(ret ? "yes\n" : "no\n");
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}