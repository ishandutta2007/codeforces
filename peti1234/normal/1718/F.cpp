#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int c=100001, pp=13, k=(1<<13), c2=2327, M=20000;
int spec[k], t[c];
short dp[k][c2];
long long prod[k];
int n, m, ert, pr_cnt, prid[c], osztdb[c], ff[c], oszt0[c], oszt1[c];
vector<int> fontos, fontos2, sz[c], oszt[c];
vector<int> kis_prim{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};



int q, ll[c], rr[c], db[c], ans[c];
bool van[c];
int mo_lepes;


long long gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	long long e=1;
	long long subSquareSize = e << (2*pow - 2);
	long long ans = seg * subSquareSize;
	long long add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}
void add(int pos) {
    for (auto x:sz[pos]) {
        db[x]++;
        van[x]=db[x];
    }
}
void sub(int pos) {
    for (auto x:sz[pos]) {
        db[x]--;
        van[x]=db[x];
    }
}
int calc() {
    int mask=0;
    for (int i=0; i<pp; i++) {
        if (db[kis_prim[i]]) {
            mask+=(1<<i);
        }
    }
    int ans=spec[mask];
    for (auto x:fontos) {
        if (van[x]) {
            ans-=dp[mask][ff[x]];
        }
    }
    short pl=0;
    for (auto x:fontos2) {
        if (van[oszt0[x]] && van[oszt1[x]]) {
            pl+=dp[mask][ff[x]];
        }
    }
    return ans+pl;
}
void mo() {
    vector<pair<long long, int> > sz;
    for (int i=1; i<=q; i++) {
        sz.push_back({gilbertOrder(ll[i], rr[i], 21, 0), i});
    }
    sort(sz.begin(), sz.end());
    int bal=1, jobb=0;
    for (auto x:sz) {
        int id=x.second;
        while (bal>ll[id]) {
            bal--;
            add(bal);
        }
        while (jobb<rr[id]) {
            jobb++;
            add(jobb);
        }
        while (bal<ll[id]) {
            sub(bal);
            bal++;
        }
        while (jobb>rr[id]) {
            sub(jobb);
            jobb--;
        }
        ans[id]=calc();
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int mask=0; mask<k; mask++) {
        prod[mask]=1;
        for (int i=0; i<pp; i++) {
            if (mask & (1<<i)) {
                prod[mask]*=kis_prim[i];
            }
        }
    }
    for (int i=1; i<c2; i++) {
        int mask2=0;
        for (int j=0; j<pp; j++) {
            if (i%kis_prim[j]==0) {
                mask2+=(1<<j);
            }
        }
        for (int mask=0; mask<k; mask++) {
            dp[mask][i]=dp[mask][i-1]+((mask & mask2)==0);
        }
    }
    for (int i=1; i<c; i++) {
        for (int j=i; j<c; j+=i) {
            osztdb[j]++;
        }
    }
    for (int i=2; i<c; i++) {
        if (!prid[i]) {
            prid[i]=++pr_cnt;
            for (int j=i; j<c; j+=i) {
                if (j>i) prid[j]=-1;
                oszt[j].push_back(i);
                if (!oszt0[j]) oszt0[j]=i;
                else oszt1[j]=i;
            }
        }
        if (oszt0[i]>42) {
            if (i<M && osztdb[i]==2) fontos.push_back(i);
            if (osztdb[i]==4 && oszt1[i]) fontos2.push_back(i);
        }
    }
    cin >> n >> m >> ert >> q;
    for (int i=1; i<=ert; i++) {
        ff[i]=ert/i;
    }

    for (int mask=0; mask<k; mask++) {
        for (int mask2=mask; ; mask2=((mask2-1) & mask)) {
            int pc=__builtin_popcount(mask2), s=(pc%2 ? -1 : 1);
            spec[mask]+=s*(ert/prod[mask2]);
            if (mask2==0) break;
        }
    }

    for (int i=1; i<=n; i++) {
        cin >> t[i];
        for (auto x:oszt[t[i]]) {
            sz[i].push_back(x);
        }
    }

    for (int i=1; i<=q; i++) {
        cin >> ll[i] >> rr[i];
    }
    mo();

    for (int i=1; i<=q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}