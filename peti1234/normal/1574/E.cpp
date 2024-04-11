#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
long long po[c], mod=998244353;
int n, m, k;
int s[c][2], o[c][2], sc, oc, us, uo, wsq, bsq;
map<pair<int, int>, int> sq;
void add(int a, int b, bool ert, int p) {
    int val=0;
    bool cl=(a+b+ert)%2;
    if (cl) {
        wsq+=p;
    } else {
        bsq+=p;
    }


    val=(b+ert)%2;
    s[a][val]+=p;
    if (p==1 && s[a][val]==1) {
        if (s[a][1-val]) {
            sc++;
        } else {
            us--;
        }
    }
    if (p==-1 && s[a][val]==0) {
        if (s[a][1-val]) {
            sc--;
        } else {
            us++;
        }
    }



    val=(a+ert)%2;
    o[b][val]+=p;
    if (p==1 && o[b][val]==1) {
        if (o[b][1-val]) {
            oc++;
        } else {
            uo--;
        }
    }
    if (p==-1 && o[b][val]==0) {
        if (o[b][1-val]) {
            oc--;
        } else {
            uo++;
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    us=n, uo=m;
    po[0]=1;
    for (int i=1; i<c; i++) {
        po[i]=po[i-1]*2%mod;
    }
    //return 0;
    for (int i=1; i<=k; i++) {
        int a, b, c;
        cin >> a >> b;
        if (sq.find({a, b})!=sq.end()) {
            int x=sq[{a, b}];
            sq.erase({a, b});
            add(a, b, x, -1);
        }
        cin >> c;
        if (c!=-1) {
            sq[{a, b}]=c;
            add(a, b, c, 1);
        }
        long long sum=0;
        if (!sc) {
            sum+=po[us];
        }
        if (!oc) {
            sum+=po[uo];
        }
        if (!wsq) {
            sum--;
        }
        if (!bsq) {
            sum--;
        }
        cout << (sum+mod)%mod << "\n";
    }
    return 0;
}