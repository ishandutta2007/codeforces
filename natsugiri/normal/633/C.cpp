#include<map>
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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N, M;
string T, S[100111];
char buf[1000111];

int dp[10111];
map<string, int> D[1011];


int main() {
    scanf("%d", &N);
    scanf("%s", buf); T = buf;
    scanf("%d", &M);
    REP (i, M) {
	scanf("%s", buf);
	S[i] = buf;

	int m = strlen(buf);
	REP (k, m) buf[k] = tolower(buf[k]);
	reverse(buf, buf+m);
	D[m][buf] = i;
    }

    memset(dp, -1, sizeof dp);
    dp[0] = -2;
    REP (i, N) if (dp[i] != -1) {
	string a;
	for (int j=i; j<N && j-i<=1002; j++) {
	    a.push_back(T[j]);
	    map<string, int>::iterator it = D[a.size()].find(a);
	    if (it != D[a.size()].end()) {
		dp[j+1] = it->second;
	    }
	}
    }

    int cur = N;
    VI ans;
    while (cur) {
	ans.push_back(dp[cur]);
	cur -= S[dp[cur]].size();
    }
    reverse(ans.begin(), ans.end());

    REP (i, ans.size()) {
	printf("%s%c", S[ans[i]].c_str(), i+1==(int)ans.size()?'\n':' ');
    }

    return 0;
}