#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 16, inf = 1e9 + 100;

pair<int, int> q[2][1 << 16];

int c[maxn], r[maxn], b[maxn];

int n;

int pos[maxn];

int ppos[maxn];

int check(){
    int ret = n, x = 0, y = 0, A = 0, B = 0;
    for (int i = 0; i < n; i++){
        int add = max(max(0, r[pos[i]] - A) - x, max(0, b[pos[i]] - B) - y);
        ret += add;
        x += add;
        y += add;
        x -= max(0, r[pos[i]] - A);
        y -= max(0, b[pos[i]] - B);
        if (c[pos[i]] == 0)
            A++;
        else
            B++;
    }
    return ret;
}

double tstart = 1000;

double temp(int i){
    return tstart;
}

double al = 0.9999;

int answer = inf;

double myrand(){
    int x = rand() + 1, y = rand() + 1;
    x %= y;
    return (double)x / y;
}

int change(){
    int s = rand() % n;
    int p = rand() % n;
    int x = pos[s];
    for (int i = s; i < n - 1; i++)
        pos[i] = pos[i + 1];
    for (int i = n - 1; i > p; i--)
        pos[i] = pos[i - 1];
    pos[p] = x;
}

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    srand(3228);
    cin >> n;
    for (int i = 0; i < n; i++){
        char x;
        cin >> x;
        if (x == 'B')
            c[i] = 1;
        cin >> r[i] >> b[i];
        pos[i] = i;
    }
    for (int i = 0; i < n; i++)
        swap(pos[i], pos[rand() % (i + 1)]);
    int it = 0;
    int podryad = 0;
    int enow = check();
    double clocks = clock();
    while ((clock() - clocks) / CLOCKS_PER_SEC <= 1.9){
        answer = min(answer, enow);
        for (int i = 0; i < n; i++)
            ppos[i] = pos[i];
        int kr = ceil(n * temp(0) / 1000.0);
        for (int i = 0; i < kr; i++)
            swap(pos[rand() % n], pos[rand() % n]);
        int newe = check();
        if (newe < enow)
            podryad = 0, it++, enow = newe;
        else
            if (myrand() <= exp(-(double)(newe - enow) / temp(it)))
                podryad = 0, it++, enow = newe;
            else
            for (int i = 0; i < n; i++)
                pos[i] = ppos[i];
        tstart *= al;
    }
    cout << answer;
}