#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL MOD = 1000000007;


int main() {
    string S;
    cin >> S;

    LL pre[3] = {1, 1, 0};
    for (int i=0; i<(int)S.size(); i++) {
	LL now[3] = {};
	
	if (S[i] == '0' || S[i] == '?') {
	    now[0] += pre[0];
	}
	if (S[i] == '1' || S[i] == '?') {
	    now[0] += pre[2];
	    now[1] += pre[0];
	}
	if (S[i] == '2' || S[i] == '?') {
	    now[1] += pre[2];
	}
	if (S[i] == '*' || S[i] == '?') {
	    now[2] += pre[1] + pre[2];
	}
	for (int j=0; j<3; j++) pre[j] = now[j] % MOD;

//	for (int j=0; j<3; j++) cout << pre[j] << ' '; cout << endl;
    }

    printf("%d\n", (int)((pre[0] + pre[2]) % MOD));
    
    return 0;
}