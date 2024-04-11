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


string S;
int main() {
    cin >> S;
    int n = S.size();
    REP (i, n-1) {
	if (S[i] % 2 == 0 && S[i] < S[n-1]) {
	    swap(S[i], S[n-1]);
	    cout << S << "\n";
	    return 0;
	}
    }
    for (int i=S.size()-2; i>=0; i--) {
	if (S[i] % 2 == 0) {
	    swap(S[i], S[n-1]);
	    cout << S << "\n";
	    return 0;
	}
    }

    cout << "-1\n";
    return 0;
}