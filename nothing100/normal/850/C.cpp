#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
const int maxn = 1100000;

map<int,int> ex;
int sg[maxn];
int a[maxn];
int prime[maxn];
bool f[maxn];
int tot;
void make_prime() {
    for (int i = 2; i <= 1000000; i++) {
        if (f[i]) continue;
        for (int j = i+i; j <= 1000000; j+=i) {
            f[j] = true;
        }
    }
    tot = 0;
    for (int i = 2; i <= 1000000; i++)
        if (!f[i]) prime[++tot] = i;
}
int ss = 1<<20;
//int ss = 1;
int dfs(int x) {
    if (x < ss) return sg[x];

    int w[41];
    for (int i = 0; i <= 35; i++) w[i] = 0;
    for (int i = 0; i <= 30; i++) {
        int xx = x >> (i+1);
        int yy = x & ((1<<(i)) - 1);
        if (i == 0) yy = 0;
        int zz = xx | yy;
        if (zz >= x) continue;
        w[dfs(zz)] = 1;
    }

    for (int i = 0; i <= 35; i++) if (w[i] == 0) return i;

    return 0;
}
int w[41];
int main() {
    //freopen("c.in","r",stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    make_prime();

    sg[0] = 0;
    for (int x = 1; x < ss; x++) {
        for (int j = 0; j <= 25; j++) w[j] = 0;
        for (int i = 0; i < 20; i++) {
            int xx = x >> (i+1);
            int yy = x & ((1<<(i)) - 1);
            if (i == 0) yy = 0;
            int zz = xx | yy;
            if (zz >= x) continue;
            w[sg[zz]] = 1;
        }
        for (int j = 0; j <= 25; j++) if (w[j] == 0) {
            sg[x] = j;
            break;
        }
    }
    int res = 0;
    for (int i = 1; i <= tot; i++) {
        int x = 0;
        for (int j = 1; j <= n; j++) {
            int sum = 0;
            while (a[j] % prime[i] == 0) {
                a[j] /= prime[i];
                sum++;
            }
            if (sum > 0) {
                sum--;
                x |= 1<<sum;
            }
        }
        if (x >= ss) res ^= dfs(x);
        else res ^= sg[x];
    }
    for (int i = 1; i <= n; i++) if (a[i] > 1&&ex[a[i]]==0) res ^= sg[1],ex[a[i]]=1;

    if (res) printf("Mojtaba\n");
    else printf("Arpa\n");

}