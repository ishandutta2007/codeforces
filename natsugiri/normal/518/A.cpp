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


string S, T, U;
int main() {
    cin >> S >> T;
    U = S;
    for (int i=U.size(); i--;) {
	if (U[i] == 'z') U[i] = 'a';
	else {
	    U[i]++;
	    break;
	}
    }
    if (S < U && U < T) cout << U << "\n";
    else cout << "No such string" << "\n";
    return 0;
}