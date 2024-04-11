#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 300005;
const int BIT = 30;

int n, cnt=1;
int a[MAXN], p[MAXN];
int l[MAXN*32], r[MAXN*32], siz[MAXN*32];

void ubaci (int x) {
    int pos=1;
    for (int pot=BIT; pot>=0; pot--) {
        siz[pos]++;
        if (x & (1<<pot)) {
            if (r[pos]==0) {
                cnt++;
                r[pos]=cnt;
            }
            pos=r[pos];
        } else {
            if (l[pos]==0) {
                cnt++;
                l[pos]=cnt;
            }
            pos=l[pos];
        }
    }
    siz[pos]++;
}

int nadi (int x) {
    int pos=1, res=0;
    for (int pot=BIT; pot>=0; pot--) {
        siz[pos]--;
        if (x & (1<<pot)) {
            if (siz[r[pos]]!=0) {
                pos=r[pos];
                res=res*2+1;
            } else {
                pos=l[pos];
                res=res*2;
            }
        } else {
            if (siz[l[pos]]!=0) {
                pos=l[pos];
                res=res*2;
            } else {
                pos=r[pos];
                res=res*2+1;
            }
        }
    }
    siz[pos]--;
    return res;
}

int main () {
    cin >> n;
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &p[i]);
        ubaci(p[i]);
    }
    for (int i=0; i<n; i++) {
        printf("%d ", nadi(a[i]) ^ a[i]);
    }
    return 0;
}