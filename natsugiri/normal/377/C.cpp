#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
using namespace std;

typedef long long LL;

int N, S[110], M;
char act[30];
int team[30];

bool use[1<<20];
int memo[1<<20];

int rec(int p, int mask) {
    if (use[mask]) return memo[mask];
    
    if (p==M) return 0;

    int ans = 0;
    if (act[p] == 'p') { // pick
	int i;
	for (i=0; i<N; i++) if (~mask&(1<<i)) break;
	ans = (team[p] == 1 ? 1 : -1) * S[i] + rec(p+1, mask|(1<<i));
    } else { // ban
	vector<int>v;
	for (int i=0; i<N; i++) {
	    if (~mask&(1<<i)) v.push_back(rec(p+1, mask|(1<<i)));
	}
	if (team[p] == 1) ans =  *max_element(v.begin(), v.end());
	else ans =  *min_element(v.begin(), v.end());
    }

    use[mask] = true;
    memo[mask] = ans;
    return ans;
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", S+i);
    sort(S, S+N);

    if (N>20) {
	for (int i=0; i<20; i++) S[i] = S[N-20+i];
	N = 20;
    }
    reverse(S, S+N);

    scanf("%d", &M);
    for (int i=0; i<M; i++) {
	char ac[8]; int t;
	scanf("%s%d", ac, &t);
	act[i] = ac[0];
	team[i] = t;
    }

    printf("%d\n", rec(0, 0));

    return 0;
}