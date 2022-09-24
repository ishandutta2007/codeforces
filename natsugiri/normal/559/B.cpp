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
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

string rec(const string &S) {
    if (S.size() & 1) {
	return S;
    } else {
	string l = S.substr(0, S.size()/2);
	string r = S.substr(S.size()/2);
	l = rec(l);
	r = rec(r);
	if (l > r) swap(l, r);
	return l + r;
    }
}


string A, B;
char buf[200111];
VI Av, Bv;
int main() {
    scanf("%s", buf); A = buf;
    scanf("%s", buf); B = buf;

    A = rec(A);
    B = rec(B);
    
    bool yes = (A == B);
    puts(yes ? "YES" : "NO");	

    
    return 0;
}