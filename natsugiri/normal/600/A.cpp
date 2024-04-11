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
vector<string> split(const string&s, char c=' ') {
    int p=0;
    vector<string>ret;
    for (int i=0; i<int(s.size()); i++) {
	if (s[i]==';' || s[i] == ',') {
	    ret.push_back(s.substr(p, i-p));
	    p=i+1;
	}
    }
    ret.push_back(s.substr(p));
    return ret;
}

bool digit(const string &s) {
    if (s == "0") return true;
    if (s.size() == 0) return false;
    if (s[0] == '0') return false;
    REP (i, s.size()) if (!isdigit(s[i])) return false;
    return true;
}

char S[100011];

int main() {
    scanf("%s", S);
    vector<string> X = split(S);
    string A, B;
    bool gA = false, gB = false;
    EACH (e, X) {
	if (digit(*e)) {
	    if (gA) A.push_back(',');
	    gA = true;
	    A += *e;
	} else {
	    if (gB) B.push_back(',');
	    gB = true;
	    B += *e;
	}
    }

    if (gA) printf("\"%s\"\n", A.c_str());
    else puts("-");

    if (gB) printf("\"%s\"\n", B.c_str());
    else puts("-");
    
    return 0;
}