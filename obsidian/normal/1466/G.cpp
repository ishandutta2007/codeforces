#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 110000;
const int N = 21;
const int M = 26;
void e_kmp(char *s,char *t,int *has,int *e_has)
{
	int sp,p,mx,tn;
	for(sp=p=mx=0;s[p]>0;p++)
	{
		if(mx==p||p+e_has[p-sp]>=mx )
		{
			for(tn=mx-p;s[mx]==t[tn];tn++)mx++;
			has[sp=p]=mx-p;
			if(mx==p)sp=++mx;
		}
		else has[p]=e_has[p-sp];
	}
}
char s[V], t[V], tr[N + 2][V * 10], r[V * 10], rr[V * 10];
char q[V * 10];
int e_has[N + 2][V * 10], has[V * 10], rhas[V * 10];
int cnt[V][M], tn[V];
int n, Q, m;
int pt[V];

int solve(int K, int L) {
    for (int i = 0; i < L; ++i) rr[i] = r[L - i - 1];
    r[L] = rr[L] = 0;
    //printf("K %d  ", K); puts(r);
    if (L == 0) return pt[K];
    int res = 0;
    for (int j = 1; j <= min(K, N); ++j) {
        e_kmp(r,tr[j],has,e_has[j]);
        //for (int j = 0; j < tn[i]; ++j) printf("%d ", e_has[i][j]); puts("ehas");
        //for (int j = 0; j < L; ++j) printf("%d ", has[i][j]); puts("has");
        e_kmp(rr,tr[j],rhas,e_has[j]);
        for (int i = 0; i < L; ++i) {
            //printf("C %d %d %d %d %d %d\n", i, j, i >= tn[j - 1], i == 0 || rhas[j - 1][L - i] >= i, L - i - 1 >= tn[j - 1], i == L - 1 || has[j - 1][i + 1] >= L - i - 1);
            if (i <= tn[j - 1] && (i == 0 || rhas[L - i] >= i)&& L - i - 1 <= tn[j - 1] && (i == L - 1 || has[i + 1] >= L - i - 1)) {
                //printf("OK %d %d\n", i, j);
                if (r[i] == t[j - 1]) {
                    //printf("ADD %d %d\n", i, j);
                    res += pt[K - j];
                    res %= P;
                }
                if(j == N && K > N) {
                    //printf("ADD2 %d %d\n", i, j);
                    res += cnt[K][r[i] - 'a'] - (LL) pt[K - N] * cnt[N][r[i] - 'a'] % P;
                    res = (res % P + P) % P;
                }
            }
        }
    }
    return res;
}

int main() {
    pt[0] = 1;
    for (int i = 1; i < V; ++i) pt[i] = pt[i - 1] * 2 % P;
    while (~scanf("%d%d", &n, &Q)) {
        scanf("%s%s", s, t);
        m = strlen(s);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < M; ++j)
                cnt[i + 1][j] = cnt[i][j] * 2 % P;
            cnt[i + 1][t[i] - 'a']++;
            cnt[i + 1][t[i] - 'a'] %= P;
            //for (int j = 0; j < M; ++j) printf("%d ", cnt[i + 1][j]); puts("");
        }
        tn[0] = 0;
        for (int i = 1; i <= min(n, N); ++i) {
            tn[i] = 0;
            if (i > 1) {
                for (int j = 0; j < tn[i - 1]; ++j)
                tr[i][tn[i]++] = tr[i - 1][j];
            }
            tr[i][tn[i]++] = t[i - 1];
            if (i > 1) {
                for (int j = 0; j < tn[i - 1]; ++j)
                tr[i][tn[i]++] = tr[i - 1][j];
            }
            tr[i][tn[i]] = -1;
            //puts(tr[i]);
            e_has[i][0] = tn[i];
            e_kmp(tr[i]+1,tr[i],e_has[i]+1,e_has[i]);
            //for (int j = 0; j < tn[i]; ++j) printf("%d ", e_has[i][j]); puts("ehas");
        }
        while (Q--) {
            int K;
            scanf("%d%s", &K, q);
            int L = strlen(q);
            int ans = 0;
            for (int i = 0; i <= m; ++i) {
                bool ok = true;
                int rl = 0;
                for (int j = 0; j < L; ++j) {
                    if ((i + j) % (m + 1) == m) r[rl++] = q[j];
                    else if (s[(i + j) % (m + 1)] != q[j]) ok = false;
                }
                if (!ok) continue;
                ans = (ans + solve(K, rl)) % P;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

/*
3 3
aa
bcd
2 aba
3 ca
3 aa

4 5
aba
bbac
1 a
3 baca
3 ab
2 bab
4 aba
*/