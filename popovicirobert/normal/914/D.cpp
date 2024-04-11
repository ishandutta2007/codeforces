#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 43

using namespace std;

inline int gcd(int a, int b) {
    int r;
    while(b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

const int MAXN = (int) 5e5;

int aint[4 * MAXN + 1];
int v[MAXN + 1];

void update(int nod, int left, int right, int pos, int val) {
    if(left == right) {
        aint[nod] = val;
    }
    else {
        int med = (left + right) / 2;
        if(pos <= med)
            update(2 * nod, left, med, pos, val);
        else
            update(2 * nod + 1, med + 1, right, pos, val);
        aint[nod] = gcd(aint[2 * nod], aint[2 * nod + 1]);
    }
}

int p;

bool query(int nod, int left, int right, int l, int x) {
    int med = (left + right) / 2;
    if(l <= left) {
        //if(l == 2)
        //printf("%d %d\n" ,left,right);
        if(left == right) {
            if(v[left] % x == 0) {
                p = right + 1;
                return 1;
            }
            else {
                p = right;
                return 0;
            }
        }
        if(aint[nod] % x == 0) {
            p = right + 1;
            return 1;
        }
        if(aint[2 * nod] % x > 0)
            query(2 * nod, left, med, l, x);
        else
            query(2 * nod + 1, med + 1, right, l, x);
    }
    else {
        bool flag = 1;
        if(l <= med)
            flag = query(2 * nod, left, med, l, x);
        if(flag == 1)
            query(2 * nod + 1, med + 1, right, l, x);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x, l, r, pos, t, q;
    //ios::sync_with_stdio(false);
    scanf("%d" ,&n);
    for(i = 1; i <= n; i++) {
        scanf("%d" ,&x);
        v[i] = x;
        update(1, 1, n, i, x);
    }
    scanf("%d" ,&q);
    while(q > 0) {
        q--;
        scanf("%d" ,&t);
        if(t == 1) {
            scanf("%d%d%d" ,&l,&r,&x);
            p = l;
            query(1, 1, n, l, x);
            p++;
            if(p <= n) {
                //printf("%d %d %d\n" ,l,r,p);
                query(1, 1, n, p, x);
                p--;
            }
            if(p >= r)
                printf("YES");
            else
                printf("NO");
            printf("\n");
        }
        else {
            scanf("%d%d" ,&pos,&x);
            v[pos] = x;
            update(1, 1, n, pos, x);
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}