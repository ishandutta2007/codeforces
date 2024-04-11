
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

const ll MOD = 1e9+7;

pii a[128];

int main(){
	int T;
	scanf("%d", &T);
	while(T--) {
		int cnt = 0, n;
		char op[16];
		scanf("%d", &n);
		for(int i = 1; i < n; i+=2) {
			printf("? %d %d\n", i, i+1);
			fflush(stdout);
			scanf("%s", op);
			//getchar();
			//cout << "kita" << endl;
			if(op[0] == '<') a[++cnt] = pii(i, i+1);
			else a[++cnt] = pii(i+1, i);
		}
		if(n & 1) a[++cnt] = pii(n, n);
		//for(int i = 1; i < cnt; i++) {
		//	cout << "a[" << i << "] : " << a[i].X << " " << a[i].Y << endl;
		//}
		for(int i = 1; i < cnt; i++) {
			printf("? %d %d\n", a[i].X, a[i+1].X);
			fflush(stdout);
			scanf("%s", op);
			//getchar();
			if(op[0] == '<') a[i+1].X = a[i].X;
			printf("? %d %d\n", a[i].Y, a[i+1].Y);
			fflush(stdout);
			scanf("%s", op);
			//getchar();
			if(op[0] == '>') a[i+1].Y = a[i].Y;
		}
		printf("! %d %d\n", a[cnt].X, a[cnt].Y);
		fflush(stdout);
	}
	return 0;
}