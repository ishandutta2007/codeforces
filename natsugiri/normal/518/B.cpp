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

int n, s, k;
int cnt[256], ccnt[256];
char buf[211111];

int main() {
    scanf("%s", buf);
    for (int i=0; buf[i]; i++) cnt[buf[i]]++;
    n = strlen(buf);
    scanf("%s", buf);
    for (int i=0; buf[i]; i++) ccnt[buf[i]]++;
    REP (i, 256) {
	int t = min(cnt[i], ccnt[i]);
	s += t;
	cnt[i] -= t;
	ccnt[i] -= t;
    }
    for (char l='a', u='A'; l<='z'; l++, u++) {
	k += min(cnt[l], ccnt[u]);
	k += min(cnt[u], ccnt[l]);
    }
    printf("%d %d\n", s, k);
    
    return 0;
}