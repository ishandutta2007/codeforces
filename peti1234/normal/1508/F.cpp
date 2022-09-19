#include <bits/stdc++.h>

using namespace std;
const int c=25005;
int n, m, cnt, perm[c], le[c], fel[c], balkis[c], balnagy[c], jobbkis[c], jobbnagy[c];
bool calc(int a, int b) {
    if (a==b) {
        return 0;
    }
    if (a>b) {
        swap(a, b);
    }
    return ((jobbnagy[a]==b && balkis[b]==a) || (jobbkis[a]==b && balnagy[b]==a));
}

void updf(int a, int b) {
    cnt-=calc(a, jobbkis[a]), cnt-=calc(a, jobbnagy[a]);
    int s=fel[a];
    while (s<b) {
        s++;
        if (perm[s]<perm[a] && (jobbkis[a]==a || perm[s]>perm[jobbkis[a]])) {
            jobbkis[a]=s;
        }
        if (perm[s]>perm[a] && (jobbnagy[a]==a || perm[s]<perm[jobbnagy[a]])) {
            jobbnagy[a]=s;
        }
    }
    cnt+=calc(a, jobbkis[a]), cnt+=calc(a, jobbnagy[a]);
    fel[a]=s;
}

void updl(int a, int b) {
    cnt-=calc(a, balkis[a]), cnt-=calc(a, balnagy[a]);
    int s=le[a];
    while (s>b) {
        s--;
        if (perm[s]<perm[a] && (balkis[a]==a || perm[s]>perm[balkis[a]])) {
            balkis[a]=s;
        }
        if (perm[s]>perm[a] && (balnagy[a]==a || perm[s]<perm[balnagy[a]])) {
            balnagy[a]=s;
        }
    }
    cnt+=calc(a, balkis[a]), cnt+=calc(a, balnagy[a]);
    le[a]=s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> perm[i];
        le[i]=fel[i]=balkis[i]=balnagy[i]=jobbkis[i]=jobbnagy[i]=i;
    }
    for (int i=1; i<=m; i++) {
        int l, r;
        cin >> l >> r;
        int pos=l;
        while (fel[pos]<r) {
            updf(pos, r);
            pos++;
        }
        pos=r;
        while (le[pos]>l) {
            updl(pos, l);
            pos--;
        }
        cout << cnt << "\n";
    }
    return 0;
}
/*
4 2
2 4 1 3
1 3
2 4
*/