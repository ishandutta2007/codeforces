#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back

struct Photo {
    long long a1, b1, a2, b2;
    Photo() {}
    Photo(long long a, long long b, long long aa, long long bb) : a1(a), b1(b), a2(aa), b2(bb) {}
    bool operator<(Photo other) const {
        return a1 + b1  < other.a1 + other.b1;
    }
};

long long n, flag, dif, tot, turn;
long long x1, y1, x2, y2;
multiset<Photo> s;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 + y1 <= x2 + y2)
        {
            if (x1 - y2 > 0) dif += x1 - y2;
            if (y1 - x2 > 0) dif += x2 - y1;
            continue;
        }
        s.insert(Photo(x1, y1, x2, y2));
    }
    //BUG(s.size());
    while (!s.empty())
    {
        auto en = s.end();
        en--;
        auto p = *en;
        if (!turn)
        {
            dif += p.a1;
        }
        else
        {
            dif -= p.b1;
        }
        if (p.a2 || p.b2)
        {
            Photo tmp = Photo(p.a2, p.b2, 0, 0);
            s.erase(en);
            s.insert(tmp);
        }
        else s.erase(en);
        turn = 1 - turn;
        //BUG(dif);
    }
    cout << dif;
}