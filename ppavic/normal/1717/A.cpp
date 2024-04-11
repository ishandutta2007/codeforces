#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

#define PB push_back
#define X first
#define Y second

using namespace std;

typedef long long ll;

ll n;

int main(){
	int T; scanf("%d", &T);
	for(;T--;){
		scanf("%lld", &n);
		printf("%lld\n", n + 2LL * (n / 2 + n / 3));
	}
	return 0;
}