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
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

string MI(int M, int S) {
    if (M == 1 && S == 0) return "0";
    if (M*9 < S || S==0) return "-1";

    string ret;
    REP (i, M) {
	int d;
	for (d=(i==0?1:0); ; d++) 
	    if (S-d <= (M-1-i)*9) break;

	S-=d;
	ret.push_back(d+'0');
    }
    return ret;
}

string MA(int M, int S) {
    if (M == 1 && S == 0) return "0";
    if (M*9 < S || S==0) return "-1";

    string ret;
    REP (i, M) {
	int d;
	for (d=min(9, S); ; d++) 
	    if (S-d <= (M-1-i)*9) break;

	S-=d;
	ret.push_back(d+'0');
    }
    return ret;
}

int main() {
    int M, S;
    scanf("%d%d", &M, &S);

    cout << MI(M, S) + " " + MA(M, S) << endl;
    return 0;
}