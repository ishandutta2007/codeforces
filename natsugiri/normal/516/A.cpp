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

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

char S[99];
int main() {
    scanf("%*d%s", S);
    VI v;
    for (int i=0; S[i]; i++) {
	if (S[i] == '0' || S[i] == '1') {
	    // nop
	} else if (S[i] == '4') {
	    v.push_back(3);
	    v.push_back(2);
	    v.push_back(2);
	} else if (S[i] == '6') {
	    v.push_back(5);
	    v.push_back(3);
	} else if (S[i] == '8') {
	    v.push_back(7);
	    v.push_back(2);
	    v.push_back(2);
	    v.push_back(2);
	} else if (S[i] == '9') {
	    v.push_back(7);
	    v.push_back(3);
	    v.push_back(3);
	    v.push_back(2);
	} else { // prime 
	    v.push_back(S[i]-'0');
	}
    }
    sort(v.rbegin(), v.rend());
    EACH (e, v) putchar(*e + '0');
    putchar('\n');
    return 0;
}