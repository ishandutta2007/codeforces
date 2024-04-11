#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000

struct ST {
    int sum[4*MAXN+2];
    int lazy[4*MAXN+2];

    ST() {
        for (int i=0; i<4*MAXN+2; i++) sum[i] = 0, lazy[i] = -1;
    }

    void propagate(int node, int l, int r) {
        if (lazy[node] == -1) return;

        for (int i=0; i<2; i++) {
            lazy[2*node+i] = lazy[node];
            sum[2*node+i] = lazy[node] * (((r-l+1) >> 1) + ((r-l+1) & 1) * (1-i));
        }
        lazy[node] = -1;
        return;
    }

    void update(int node, int l, int r, int a, int b, int val) {
        if (l > b || r < a) return;
        if (l >= a && r <= b) {
            lazy[node] = val;
            sum[node] = (r-l+1) * val;
            return;
        }

        propagate(node, l, r);
        int mid = (l + r) >> 1;
        update(2*node+0, l, mid+0, a, b, val);
        update(2*node+1, mid+1, r, a, b, val);
        sum[node] = sum[2*node] + sum[2*node+1];
        return;
    }

    int query(int node, int l, int r, int a, int b) {
        if (l > b || r < a) return 0;
        if (l >= a && r <= b) return sum[node];

        propagate(node, l, r);
        int mid = (l + r) >> 1;
        return query(2*node, l, mid, a, b) + query(2*node+1, mid+1, r, a, b);
    }
};

int n, q;
char s[MAXN+2];
ST alfa[26];

int main() {
    scanf("%d %d\n", &n, &q);
    gets(s);

    for (int i=0; i<n; i++) alfa[s[i]-'a'].update(1, 1, n, i+1, i+1, 1);
    int l, r, k;
    while (q--) {
        scanf("%d %d %d", &l, &r, &k);
        if (k) {
            int now = l;
            for (int i=0; i<26; i++) {
                int tmp = alfa[i].query(1, 1, n, l, r);
                alfa[i].update(1, 1, n, l, r, 0);
                alfa[i].update(1, 1, n, now, now+tmp-1, 1);
                now += tmp;
            }
        } else {
            int now = r;
            for (int i=0; i<26; i++) {
                int tmp = alfa[i].query(1, 1, n, l, r);
                alfa[i].update(1, 1, n, l, r, 0);
                alfa[i].update(1, 1, n, now-tmp+1, now, 1);
                now -= tmp;

            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<26; j++) if (alfa[j].query(1, 1, n, i+1, i+1)) {
            printf("%c", j+'a');
            break;
        }
    }
    printf("\n");
    return 0;
}