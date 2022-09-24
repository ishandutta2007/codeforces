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
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

struct Data {
    int sx, sy;
    int le, ri, to, bo; // include?
    bool operator<(const Data &y) const { // ord by x
	return sx < y.sx;
    }
};

int N, Q;
int main() {
    scanf("%d%d", &N, &Q);

    set<Data> S;
    S.insert((Data){ 1, 1, 1, N, 1, N });
    Data seek;
    
    REP ($, Q) {
	int col, row; char buf[8], dir;
	scanf("%d%d%s", &col, &row, buf);
	dir = buf[0];

	int ans = 0;
	
	seek.sx = col;
	set<Data>::iterator it = S.upper_bound(seek);
	
	if (it != S.begin()) {
	    it--;
	    if (it->sx <= col && col <= it->ri) {
		Data D = *it;
		S.erase(it);
		// eprintf("%c %d %d %d %d %d %d\n", dir, D.sx, D.sy, D.le, D.ri, D.to, D.bo);
		if (dir == 'U') {
		    ans = row - D.to + 1;
		    if (D.sx < col)
			S.insert((Data){ D.sx, row+1, D.le, col-1, D.to, D.bo });
		    if (col < D.ri)
			S.insert((Data){ col+1, D.sy, col+1, D.ri, D.to, row-1 });
		} else {
		    ans = col - D.le + 1;
		    if (D.sy < row)
			S.insert((Data){ col+1, D.sy, D.le, D.ri, D.to, row-1 });
		    if (row < D.bo)
			S.insert((Data){ D.sx, row+1, D.le, col-1, row+1, D.bo });
		}
	    } else {
		ans = 0;
	    }
	} else {
	    ans = 0;
	}

	printf("%d\n", ans);
    }
    
    return 0;
}