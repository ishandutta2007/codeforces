#include <bits/stdc++.h>

using namespace std;

const int c=300002, gy=600, k=20;
int n, q, t[c];
int cnt, be[c], ki[c], sor[2*c], szint[c], fel[c][k];
int csop[gy], ll=1, rr, oszt[c], gyoszt[c], ans[c];
int kezd[c], veg[c], kis[c], nagy[c], spec[c];
vector<int> sz[c];
bool v[c], db[c];
vector<pair<long long, int> > mo;

void dfs(int a) {
    be[a]=++cnt;
    sor[cnt]=a;
    v[a]=true;
    for (int i=1; i<k; i++) {
        fel[a][i]=fel[fel[a][i-1]][i-1];
    }
    for (int x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x][0]=a;
            dfs(x);
        }
    }
    ki[a]=++cnt;
    sor[cnt]=a;
}

int lca(int a, int b) {
    if (szint[a]<szint[b]) {
        swap(a, b);
    }
    for (int i=k-1; i>=0; i--) {
        if (szint[fel[a][i]]>=szint[b]) {
            a=fel[a][i];
        }
    }
    for (int i=k-1; i>=0; i--) {
        if (fel[a][i]!=fel[b][i]) {
            a=fel[a][i], b=fel[b][i];
        }
    }
    if (a!=b) {
        a=fel[a][0];
    }
    return a;
}

void add(int a) {
    int ert=t[sor[a]];
    db[ert]=!db[ert];
    if (db[ert]) {
        csop[gyoszt[ert]]++;
    } else {
        csop[gyoszt[ert]]--;
    }
}

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
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	long long ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=gy; i<=n; i+=gy) {
        oszt[i]=i/gy;
    }
    for (int i=1; i<=n; i++) {
        gyoszt[i]=i/gy;
    }
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    szint[1]=1;
    dfs(1);
    for (int i=1; i<=q; i++) {
        int a, b, c, d, s;
        cin >> a >> b >> c >> d;
        if (be[a]>be[b]) {
            swap(a, b);
        }
        s=lca(a, b);
        if (a==s) {
            a=be[a], b=be[b];
        } else {
            a=ki[a], b=be[b];
            spec[i]=s;
        }
        kezd[i]=a, veg[i]=b, kis[i]=c, nagy[i]=d;
        long long ert=gilbertOrder(a, b, 20, 0);
        mo.push_back({ert, i});
    }
    sort(mo.begin(), mo.end());
    for (int i=0; i<q; i++) {
        int id=mo[i].second;
        int bb=kezd[id], jj=veg[id];
        while (ll>bb) {
            add(--ll);
        }
        while (ll<bb) {
            add(ll++);
        }
        while (rr<jj) {
            add(++rr);
        }
        while (rr>jj) {
            add(rr--);
        }
        add(be[spec[id]]);
        int valasz=0, bal=kis[id], jobb=nagy[id];
        while (bal<=jobb) {
            if (oszt[bal] && !csop[oszt[bal]]) {
                bal+=gy;
            } else {
                if (db[bal]) {
                    valasz=bal;
                    break;
                }
                bal++;
            }
        }
        if (!valasz) {
            valasz=-1;
        }
        ans[id]=valasz;

        add(be[spec[id]]);
    }
    for (int i=1; i<=q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}