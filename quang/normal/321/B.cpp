#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX 8888
#define N 110

using namespace std;

int  n, m, sla, slb;
string s;
int A[N], B[N], C[N];
bool used[N];

void Sortall() {
    sort(A + 1, A + sla + 1);
    sort(B + 1, B + slb + 1);
    sort(C + 1, C + m + 1);
}

long long Case1() {
    long long res = 0;
    for(int k = 1; k <= min(sla, m); k++) {
        long long sum = 0;
        for(int i = 1; i <= k; i++)
            if(A[i] < C[m - k + i]) sum += C[m - k + i] - A[i];
            else return res;
        res = max(res, sum);
    }
    return res;
}

long long Case2() {
    int cur = 1;
    for(int i = 1; i <= slb; i++) {
        while(C[cur] <= B[i]) cur++;
        if(cur > m) return 0;
        used[cur] = 1;
        cur++;
    }
    long long res = 0;
    cur = 1;
    bool flag = 0;
    for(int i = 1; i <= sla; i++) {
        while(C[cur] < A[i] || used[cur]) cur++;
        if(cur > m) {
            flag = 1;
            break;
        }
        used[cur] = 1;
        res += 1ll * C[cur] - A[i];
        cur++;
    }
    if(!flag)
    for(int i = 1; i <= m; i++)
    if(!used[i]) res += C[i];
    return res;
}

int main() {
    //fi, fo;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> s >> x;
        if(s[0] == 'A') A[++sla] = x;
        else B[++slb] = x;
    }
    for(int i = 1; i <= m; i++) cin >> C[i];
    C[m + 1] = MAX;
    Sortall();
    long long p1 = Case1();
    long long p2 = Case2();
    cout << max (max(p1, p2), 0ll);
    return 0;
}