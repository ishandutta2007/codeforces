#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<cstring>
using namespace std;

typedef long long LL;

LL A;
int N;
string S;
map<LL,LL> mp;
LL zero, posi;


int main() {
    cin >> A >> S;
    N = S.size();
    for (int i=0; i<N; i++) {
	LL sum = 0;
	for (int j=i; j<N; j++) {
	    sum += S[j] - '0';
	    mp[sum]++;

	    if (sum) posi++;
	    else zero++;
	}
    }

    
    LL ans = 0;

    if (A == 0) {
	ans = 2 * zero * posi + zero * zero;
    } else {
	for (LL i=1; i*i<=A; i++) {
	    if (A % i == 0) {
		LL tmp = mp[i] * mp[A/i];
		if (i*i != A) tmp *= 2;
		ans += tmp;
	    }
	}
    }

    cout << ans << endl;

    return 0;
}