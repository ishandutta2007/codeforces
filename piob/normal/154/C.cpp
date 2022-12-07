#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
typedef long double K;

const K PI = acos((long double)-1);

int n, m;
LL r;
vector<int> S[1000010];
LL H[1000010];

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,m){
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		S[a].push_back(b);
		S[b].push_back(a);
	}
	FWD(q,0,2){
		FWD(i,0,n){
			sort(S[i].begin(), S[i].end());
			H[i] = S[i].size();
			for(int j : S[i]){
				H[i] = H[i]*1000003 + (j+1);
//				H[i] %= 1000000000000037LL;
			}
		}
		sort(H, H+n);
		int p=0, k=0;
		while(p < n){
			while(k < n && H[p] == H[k]) ++k;
			LL s = k-p;
			r += s*(s-1)/2;
			p = k;
		}
		FWD(i,0,n) S[i].push_back(i);
	}
	cout << r << endl;
	return 0;
}