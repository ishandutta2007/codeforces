#include<set>
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

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int N, M, T, A[20111];
int ans[20111];
int main() {
    scanf("%d%d%d", &N, &M, &T);
    REP (i, N) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        A[i] = (h*60+m)*60+s;
    }
    sort(A, A+N);

    int R = 0;
    set<pair<int, int> > se;
    bool yes = false;
    REP (i, N) {
        while (se.size() && se.begin()->first < A[i]) se.erase(se.begin());

//        EACH (e, se) cerr << '(' << e->first << ", " << e->second << ')' << " "; cerr << "\n";
        if ((int)se.size() == M) {
            //yes = true;
            pair<int, int> p = *(se.rbegin());
            se.erase(p);
            p.first = A[i] + T - 1;
            ans[i] = p.second;
            se.insert(p);
        } else {
            ans[i] = ++R;
            pair<int, int> p(A[i] + T - 1, R);
            se.insert(p);
            if ((int)se.size() == M) yes = true;
        }
    }

    if (yes) {
        printf("%d\n", R);
        REP (i, N) printf("%d\n", ans[i]);
    } else {
        puts("No solution");
    }
    return 0;
}