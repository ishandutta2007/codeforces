#include<bits/stdc++.h>

using namespace std;
#define ll long long

int T, n, x, y;
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &x, &y);
		bool sx=0;
		for(int i=1, s; i<=x; ++i) scanf("%d", &s), sx|=s==n;
		for(int i=1, s; i<=y; ++i) scanf("%d", &s);
		puts(sx?"YES":"NO");
	}
	return 0;
}