#include <bits/stdc++.h>

using namespace std;
const int c=10000005;
int n, cnt, maxi, xx, yy, si1[c], id1[c], ki[c], si2[c], id2[c];
map<int, int> m;
int inv(int x) {
    int po=(1<<(31-__builtin_clz(2*x-1)));
    return po-x;
}
void calc(int x, int el, int len, int cs) {
    int pos=m[x], ert=(el==ki[pos] ? si2[pos] : si1[pos]);
    if (len+ert>maxi) {
        maxi=len+ert;
        xx=(el==ki[pos] ? id2[pos] : id1[pos]), yy=cs;
    }

    if (len>=si2[pos]) {
        if (len>=si1[pos]) {
            if (el!=ki[pos]) {
                si2[pos]=si1[pos];
                id2[pos]=id1[pos];
            }
            si1[pos]=len;
            id1[pos]=cs;
            ki[pos]=el;
        } else if (el!=ki[pos]) {
            si2[pos]=len;
            id2[pos]=cs;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, db=0;
        cin >> x;
        if (m.find(x)!=m.end()) {
            calc(x, -1, 0, i);
            continue;
        }
        m[x]=++cnt;
        si1[cnt]=0, si2[cnt]=-c;
        id1[cnt]=i;
        do {
            int kov=inv(x);
            db++;
            if (m.find(kov)==m.end()) {
                m[kov]=++cnt;
                si1[cnt]=-c, si2[cnt]=-c;
            }
            calc(kov, x, db, i);
            x=kov;
        } while(x>0);
    }

    cout << xx << " " << yy << " " << maxi << "\n";
    return 0;
}
/*
2
1 3
*/