#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int main() {
    string S;
    cin >> S;

    S += "9";

    ULL ans = 1;
    ULL cnt=0;
    for (int i=1; i<(int)S.size(); i++) {
	if ((int)(S[i]-'0') + (S[i-1]-'0') == 9) {
	    cnt++;
	} else {
	    if (cnt%2==0) ans *= cnt/2+1;
	    cnt=0;
	}
    }

    cout << ans << endl;
    return 0;
}