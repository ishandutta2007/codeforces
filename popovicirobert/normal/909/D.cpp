#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 1e6 + 5;

string str;

pair <char, int> sol[MAXN + 1], aux[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i, j;
    ios::sync_with_stdio(false);
    cin >> str;
    n = str.size();
    int sz = 0;
    i = 0;
    while(i < n) {
        j = i;
        while(j < n && str[j] == str[i]) {
            j++;
        }
        sol[++sz] = {str[i], j - i};
        i = j;
    }
    int ans = 0;
    while(1) {
        ans++;
        bool flag = 0;
        n = sz;
        sol[0].first = sol[1].first;
        sol[n + 1].first = sol[n].first;
        for(i = 1; i <= n; i++) {
            if(sol[i].second == 1) {
                if(sol[i - 1].first != sol[i].first || sol[i + 1].first != sol[i].first) {
                    aux[i] = {sol[i].first, 0};
                    flag = 1;
                }
                else {
                    aux[i] = sol[i];
                }
            }
            else {
                int cnt = 0;
                if(sol[i].first != sol[i - 1].first)
                   cnt++;
                if(sol[i].first != sol[i + 1].first)
                   cnt++;
                if(cnt)
                    flag = 1;
                aux[i] = {sol[i].first, sol[i].second - cnt};
            }
        }
        if(flag == 0)
            break;
        sz = 0;
        for(i = 1; i <= n; i++) {
            if(aux[i].second > 0)
                sol[++sz] = aux[i];
        }
    }
    cout << ans - 1;
    //cin.close();
    //cout.close();
    return 0;
}