#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, m, k;
int a[1010101];
int s[1010101];
vector<pair<pair<int,int>,pair<int,int>>> v;
#define F first
#define S second
#define PB push_back
#define MP make_pair

ll r[101010];
int c[2020202];
ll t = 0;

void lisaa(int i) {
    t += c[s[i]^k];
    c[s[i]]++;
}

void poista(int i) {
    c[s[i]]--;
    t -= c[s[i]^k];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i-1]^a[i];
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v.PB(MP(MP(a/500,b),MP(a,i)));
    }
    sort(v.begin(),v.end());
    int x = 1, y = 0;
    c[0] = 1;
    for (int i = 0; i < v.size(); i++) {
        int ux = v[i].S.F;
        int uy = v[i].F.S;
        while (y < uy) {y++; lisaa(y);}
        while (x > ux) {x--; lisaa(x-1);}
        while (y > uy) {poista(y); y--;}
        while (x < ux) {poista(x-1); x++;}
        r[v[i].S.S] = t;
    }
    for (int i = 1; i <= m; i++) cout << r[i] << "\n";
}