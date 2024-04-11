#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0; i<int(n); i++)

int N, P;
string S;
int main() {
    cin >> N >> P;
    cin >> S;
    P--;
    P = min(P, N-1-P);
    int cst = 0;
    int mi = -1, ma = -1;

    REP (i, N/2) {
	int tmp = abs((int)S[i] - (int)S[N-1-i]);
	tmp = min(tmp, 26-tmp);
	cst += tmp;

	if (tmp) {
	    if (mi == -1) mi = i;
	    ma = i;
	}
    }

    if (mi != -1) {
	cst += ma - mi + min(abs(P-mi), abs(ma-P));
    }
    printf("%d\n", cst);
    
    return 0;
}