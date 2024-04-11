#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int mem[100];
int N, K;

int game(int x) {
    if (x < 100) return mem[x];
    if (x % 2) return 0;

    if (K == 0) {
	return 1;
    } else {
	int z = game(x/2);
	if (z == 1) return 2;
	return 1;
    }
}

int main() {
    scanf("%d%d", &N, &K);
    K %= 2;

    for (int i=1; i<100; i++) {
	VI v;
	v.push_back(mem[i-1]);
	
	if (i % 2 == 0) {
	    v.push_back( K ? mem[i/2]: 0 );
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	v.push_back(-1);
	REP (j, 100) if (v[j] != j) {
	    mem[i] = j;
	    break;
	}

	// printf("%d %d\n", i, mem[i]);
    }

    
    int nim = 0;
    REP (i, N) {
	int x;
	scanf("%d", &x);

	nim ^= game(x);
    }

    puts(nim ? "Kevin" : "Nicky");
    return 0;
}