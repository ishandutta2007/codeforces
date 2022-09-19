#include <bits/stdc++.h>

using namespace std;
const int c=1500002, c2=502, mod=998244353;
long long specdb, ans=1, t[c2], n;
vector<long long> ert;
vector<pair<int, long long> > sor;
set<long long> po[6];
map<long long, int> m[5], pr1, pr2;
bool pr[c], dupla[c2];
void add(int a, int b) {
    for (long long i=2; i<=b; i++) {
        if (pr[i]) {
            continue;
        }
        long long ert=1;
        for (int j=1; j<=a; j++) {
            ert*=i;
        }
        po[a].insert(ert);
        m[a][ert]=i;
    }

}
int main()
{
    for (int i=2; i<c; i++) {
        if (!pr[i]) {
            for (int j=2*i; j<c; j+=i) {
                pr[j]=1;
            }
        }
    }
    add(3, 1260000), add(4, 40000);
    cin >> n;
    for (int i=1; i<=n; i++) {
        long long x;
        cin >> x;
        bool jo=1;
        long long gyok=sqrt(x);
        if (gyok*gyok==x) {
            jo=0;
        }
        if (po[3].find(x)!=po[3].end()) {
            jo=0;
        }
        sor.push_back({jo, x});
    }
    sort(sor.begin(), sor.end());
    for (int i=1; i<=n; i++) {
        long long x=sor[i-1].second;

        bool jo=0;
        for (int j=3; j<=4; j++) {
            if (po[j].find(x)!=po[j].end()) {
                pr1[m[j][x]]+=j;
                t[i]=m[j][x];
                jo=1;
            }
        }
        if (!jo) {
            long long gyok=sqrt(x);
            if (gyok*gyok==x) {
                pr1[gyok]+=2;
                t[i]=gyok;
                jo=1;
            }
        }
        if (!jo) {
            int db=2;
            for (int j=1; j<i; j++) {
                long long s=__gcd(x, t[j]);
                if (s!=1) {
                    if (db==2 && s==x) {
                        pr2[x]++;
                        x=1, db=0;
                    } else {
                        db--, x/=s;
                        if (dupla[j]) {
                            dupla[j]=0;
                            long long cnt=pr2[t[j]];
                            pr2[t[j]]=0;
                            pr1[s]+=cnt+1;
                            pr1[t[j]/s]+=cnt;
                        } else {
                            pr1[s]++;
                        }
                    }
                }
            }
            if (db==1) {
                pr1[x]++;
            }
            if (db==2) {
                pr2[x]++;
                dupla[i]=1;
            }
            t[i]=x;
        }
    }
    for (auto s:pr1) {
        int ert=s.second+1;
        ans*=ert, ans%=mod;
    }
    for (auto s:pr2) {
        int ert=s.second+1;
        ans*=ert*ert; ans%=mod;
    }
    cout << ans << "\n";
    return 0;
}