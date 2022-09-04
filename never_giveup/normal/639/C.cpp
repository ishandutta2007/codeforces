#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 7e6 + 10;

const ll inf = 1e18 + 1;

int n, k, a[maxn];

bool p[2][maxn], z[maxn];

int ang;

bool nm[32];

int len = 0;

int one[maxn], sz = 0;

void sklad(int t, int st){
    int f = 0;
    for (int i = 0; i < 32; i++)
        f += p[t][i + st] + nm[i], p[t][i + st] = f % 2, f /= 2;
    int i = 32 + st;
    while (f > 0)
        f += p[t][i], p[t][i] = f % 2, f /= 2, i++;
    len = max(len, i);
}

void razlog(int v){
    for (int j = 0; j < 32; j++)
        nm[j] = 0;
    for (int j = 0; j < 32; j++)
        nm[j] = v % 2, v /= 2;
}

bool check(int st, int t){
    int mas[32], sz1 = 0;
    for (int i = 31; i >= 0; i--)
        if (nm[i] == 1)
            mas[sz1] = i + st, sz1++;
    for (int i = 0; i < min(sz, sz1); i++){
        if (one[i] > mas[i])
            return 0;
        if (one[i] < mas[i])
            return 1;
    }
    if (sz <= sz1)
        return 1;
    return 0;
}

void init(){
    for (int i = len - 1; i >= 0; i--)
        if (p[ang][i] == 1)
            one[sz] = i, sz++;
}

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++){
        razlog(abs(a[i]));
        if (a[i] >= 0)
            sklad(0, i);
        else
            sklad(1, i);
    }
    bool is = 1;
    for (int i = 0; i < len && is; i++)
        if (p[0][i] != p[1][i])
            is = 0;
    razlog(abs(a[n]));
    if (a[n] >= 0)
        sklad(0, n);
    else
        sklad(1, n);
    for (int i = len - 1; i >= 0; i--)
        if (p[0][i] > p[1][i]){
            ang = 0;
            break;
        }
        else
        if (p[0][i] < p[1][i]){
            ang = 1;
            break;
        }
    int f = 0;
    for (int i = 0; i < len; i++){
        if (f == 0)
            if (p[ang][i] > p[ang ^ 1][i])
                continue;
            else
            if (p[ang][i] == p[ang ^ 1][i])
                p[ang][i] = 0;
            else
                p[ang][i] = 1, f = 1;
        else
            if (p[ang][i] > p[ang ^ 1][i])
                p[ang][i] = 0, f = 0;
            else
            if (p[ang][i] == 1)
                continue;
            else
                if (p[ang ^ 1][i] == 0)
                    p[ang][i] = 1;
                else
                    continue;
    }
    z[0] = 1;
    for (int i = 1; i < len; i++)
        if (p[ang][i - 1] == 1)
            z[i] = 0;
        else
            z[i] = z[i - 1];
    int answer = 0;
    init();
    for (int i = 0; i <= n; i++)
    if (z[i] && (i < n || (i == n && !is))){
        if (ang == 1){
            razlog(k - a[i]);
            if (check(i, ang))
                answer++;
        }
        else{
            razlog(a[i] + k);
            if (check(i, ang))
                answer++;
        }
    }
    cout << answer;
}