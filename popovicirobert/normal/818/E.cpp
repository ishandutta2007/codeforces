#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;

int v[MAXN + 1];

vector < pair <int, int> > prime;

int ind[MAXN + 1];

inline int check(int a, int b) {
    int cnt = 0;
    while(a % b == 0) {
        a /= b;
        cnt++;
    }
    return cnt;
}

int main() {
  //  ifstream cin("B.in");
   // ofstream cout("B.out");
    int n, k, i;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    int d = 2;
    while(d * d  <= k) {
        int e = 0;
        while(k % d == 0) {
            k /= d;
            e++;
        }
        if(e > 0)
          prime.push_back({d, e});
        d++;
    }
    if(k > 1)
        prime.push_back({k, 1});
    for(i = 1; i <= n; i++)
        ind[i] = i;
    for(auto it : prime) {
        int poz = 1;
        int sum = 0;
        for(i = 1; i <= n; i++) {
            if(poz < i) {
               poz = i;
               sum = 0;
            }
            while(poz <= n && sum + check(v[poz], it.first) < it.second) {
                sum += check(v[poz], it.first);
                poz++;
            }
            ind[i] = max(ind[i], poz);
            sum -= check(v[i], it.first);
        }
    }
    long long ans = 0;
    for(i = 1; i <= n; i++) {
        ans += n - ind[i] + 1;
        //printf("%d " ,ind[i]);
    }
    cout << ans;
  //  cin.close();
  //  cout.close();
    return 0;
}