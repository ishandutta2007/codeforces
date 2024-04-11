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

const LL MOD = 1000000007 ;

string S;
int N;
LL D[10], L[10];
pair<int, string> Z[100011];

pair<int, string> read() {
    string X;
    cin >> X;
    return make_pair(X[0] - '0', X.substr(3));
}


LL powMod(LL x, LL y, LL m) {
    LL r = 1;
    for (;y; y>>=1) {
	if (y&1) r = r * x % m;
	x = x * x % m;
    }
    return r;
}
	
pair<LL, LL> calc(const string &s) {
    LL val = 0, len = 0;
    
    for (int i=s.size(); i--;) {
	int c = s[i]-'0';
	val = (val + powMod(10, len, MOD) * D[c]) % MOD;
	len = (len + L[c]) % (MOD - 1);
    }

    return make_pair(val, len);
}

int main() {
    cin >> S >> N;
    REP (i, 10) {
	D[i] = i;
	L[i] = 1;
    }

    REP (i, N) Z[i] = read();

    for (int i=N; i--;) {
	pair<LL, LL> p = calc(Z[i].second);
	D[Z[i].first] = p.first;
	L[Z[i].first] = p.second;
    }

    cout << calc(S).first << endl;
    
    return 0;
}