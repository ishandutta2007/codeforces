#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef vector<int> VI;
typedef long long LL;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

int N, P;
string S, ans;

bool rec(char pre, char ppre, bool f, int i) {
    if (i == (int)S.size()) {
	return S != ans;
    }
    
    for (char c = (f ? 'a' : S[i]); c <= 'a'+P-1; c++) {
	if (c != pre && c != ppre) {
	    ans[i] = c;
	    if (rec(c, pre, f || (c != S[i]), i+1)) return true;
	    ans[i] = S[i];
	}
    }
    return false;
}

int main() {
    cin >> N >> P >> S;
    ans = S;
    if (rec('_', '_', false, 0))cout << ans << endl;
    else  puts("NO");

    return 0;
}