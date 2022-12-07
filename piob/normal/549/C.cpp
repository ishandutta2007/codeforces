#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n, k;
int odd, even;

int main(){
	scanf("%d %d", &n, &k);
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		if(a&1) ++odd;
		else ++even;
	}
	if(n == k){
		if(odd&1)
			printf("Stannis\n");
		else
			printf("Daenerys\n");
	}else if((n-k)&1){
		int s = (n-k)/2;
		bool w = 0;
		if(odd <= s) w = 1;
		if(even <= s){
			odd -= (n-k-even);
			if((odd&1) == 0) w = 1;
		}
		if(w)
			printf("Daenerys\n");
		else
			printf("Stannis\n");
	}else{
		int s = (n-k+1)/2;
		bool w = 0;
		if(even <= s && ((odd-(n-k-even))&1)) w = 1;
		if(w)
			printf("Stannis\n");
		else
			printf("Daenerys\n");
	}
	return 0;
}