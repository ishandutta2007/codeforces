#include <bits/stdc++.h>

using namespace std;
const int c=100002, k=20;
long long n, ert, mini, maxi, rf[c], aktert;
int akt[c], invakt[c];
int fel[c][k], szint[c];
int kis[c], invkis[c], kiscnt;
int nagy[c], invnagy[c], nagycnt, kie[c], hkie[c], maxcsop, kuldb, pos;
vector<int> sz[c];
bool v[c], v2[c];
void dfs(int a) {
    v[a]=true;
    rf[a]++;
    for (int i=1; i<k; i++) {
        fel[a][i]=fel[fel[a][i-1]][i-1];
    }

    for (int x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x][0]=a;
            dfs(x), rf[a]+=rf[x];
        }
    }
    for (int x:sz[a]) {
        if (szint[x]>szint[a]) {
            if (rf[x]%2) {
                kis[x]=++kiscnt;
            }
        }
    }
    mini+=rf[a]%2;
    if (rf[a]%2==0) {
        kis[a]=++kiscnt;
    }
    if (!pos && 2*rf[a]>n) {
        pos=a;
    }
    maxi+=min(rf[a], n-rf[a]);
}
void dfs2(int a) {
    v2[a]=true;
    int s=kie[a];
    hkie[s]++;
    if (hkie[s]>hkie[maxcsop]) {
        maxcsop=s;
    }
    for (int x:sz[a]) {
        if (!v2[x]) {
            kie[x]=s;
            dfs2(x);
        }
    }
}
bool jo(int a, int b, bool s) {
    if (nagy[a] || nagy[b] || kie[a]==kie[b]) {
        return 0;
    }
    return ((kie[a]==maxcsop)==s);
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
int csucstav(int a, int b) {
    return szint[a]+szint[b]-2*szint[lca(a, b)];
}
int valt(int a) {
    if (a%2) {
        return a+1;
    }
    return a-1;
}
void csere(int aa, int bb) {
    if (aa==bb) {
        return;
    }
    int erta=akt[aa], ertb=akt[bb], para=valt(erta), parb=valt(ertb);

    aktert-=csucstav(aa, invakt[para]);
    aktert-=csucstav(bb, invakt[parb]);

    swap(akt[aa], akt[bb]);
    swap(invakt[erta], invakt[ertb]);

    erta=akt[aa], ertb=akt[bb], para=valt(erta), parb=valt(ertb);

    aktert+=csucstav(aa, invakt[para]);
    aktert+=csucstav(bb, invakt[parb]);

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> ert;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    szint[1]=1;
    dfs(1);


    if (ert%2!=mini%2 || ert<mini || ert>maxi) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    kie[pos]=pos;
    v2[pos]=1;
    for (int x:sz[pos]) {
        kie[x]=x;
        dfs2(x);
    }
    kuldb=n/2-hkie[maxcsop];
    int ss=1;
    for (int i=1; i<=n; i++) {
        while (nagy[ss] || kie[ss]==maxcsop) {
            ss++;
        }
        if (kuldb && jo(i, ss, 0)) {
            nagy[i]=++nagycnt;
            nagy[ss]=++nagycnt;
            kuldb--;
        }
    }
    ss=1;
    for (int i=1; i<=n; i++) {
        while (nagy[ss] || kie[ss]==maxcsop) {
            ss++;
        }
        if (jo(i, ss, 1)) {
            nagy[i]=++nagycnt;
            nagy[ss]=++nagycnt;
        }
    }
    aktert=mini;

    for (int i=1; i<=n; i++) {
        invkis[kis[i]]=i;
        invnagy[nagy[i]]=i;
    }

    for (int i=1; i<=n; i++) {
        akt[i]=kis[i];
        invakt[i]=invkis[i];
    }
    for (int i=1; i<=n; i++) {
        if (aktert==ert) {
            break;
        }
        int aa=i, bb=invakt[nagy[i]];
        csere(aa, bb);
        if (aktert>ert) {
            csere(aa, bb);
            vector<int> ut, ut2;
            int kozep=lca(aa, bb), sa=aa, sb=bb;
            while (sa!=kozep) {
                ut.push_back(sa);
                sa=fel[sa][0];
            }
            while (sb!=kozep) {
                ut2.push_back(sb);
                sb=fel[sb][0];
            }
            ut.push_back(kozep);
            reverse(ut2.begin(), ut2.end());
            for (int i:ut2) {
                ut.push_back(i);
            }
            int si=ut.size();
            for (int i=0; i<si-1; i++) {
                csere(ut[i], ut[i+1]);
                if (aktert==ert) {
                    break;
                }
            }
            if (aktert==ert) {
                break;
            }
            for (int i=si-2; i>0; i--) {
                csere(ut[i], ut[i-1]);
                if (aktert==ert) {
                    break;
                }
            }
        }
    }
    long long sum=0;
    for (int i=1; i<=n; i+=2) {
        sum+=csucstav(invakt[i], invakt[i+1]);
        cout << invakt[i] << " " << invakt[i+1] << "\n";
    }
    return 0;
}