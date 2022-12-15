#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second
#define offset 1100

struct Piece{
    char c;
    long long x, y;
    Piece(char cc, long long xx, long long yy) {
        x = xx; y = yy; c = cc;
    }
    Piece() {}
};

long long n, x0, y0, x, y;
char c;
pair<long long, int> p[500005];
bool blk[8];
Piece tmp, lis[500005];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> x0 >> y0;
    REP (i, n)
    {
        cin >> c >> x >> y;
        lis[i] = Piece(c, x, y);
        p[i] = {sqr(x - x0) + sqr(y - y0), i};
    }
    sort(p, p + n);
    REP (i, 8) blk[i] = false;
    REP (i, n)
    {
        tmp = lis[p[i]._2];
        bool rook = (tmp.c == 'Q' || tmp.c == 'R');
        bool bish = (tmp.c == 'Q' || tmp.c == 'B');
        if (tmp.x == x0)
        {
            if (tmp.y > y0)
            {
                if (!blk[0] && rook) {cout << "YES"; return 0;}
                blk[0] = true;
            }
            else
            {
                if (!blk[4] && rook) {cout << "YES"; return 0;}
                blk[4] = true;
            }
        }
        if (tmp.y == y0)
        {
            if (tmp.x > x0)
            {
                if (!blk[2] && rook) {cout << "YES"; return 0;}
                blk[2] = true;
            }
            else
            {
                if (!blk[6] && rook) {cout << "YES"; return 0;}
                blk[6] = true;
            }
        }
        if (tmp.x - tmp.y == x0 - y0)
        {
            if (tmp.x > x0)
            {
                if (!blk[1] && bish) {cout << "YES"; return 0;}
                blk[1] = true;
            }
            else
            {
                if (!blk[5] && bish) {cout << "YES"; return 0;}
                blk[5] = true;
            }
        }
        if (tmp.x + tmp.y == x0 + y0)
        {
            if (tmp.x > x0)
            {
                if (!blk[3] && bish) {cout << "YES"; return 0;}
                blk[3] = true;
            }
            else
            {
                if (!blk[7] && bish) {cout << "YES"; return 0;}
                blk[7] = true;
            }
        }
    }
    cout << "NO";
}