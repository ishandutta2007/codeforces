#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = (int) 1e5;

int sol[MAXN + 1];

pair <int, int> q[4 * MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n, i, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if(k % 2 == 0)
        cout << -1;
    else {
        int b = 0, e = 1;
        int val = n;
        q[0] = {0, n};
        k--;
        while(b < e) {
            pair <int, int> aux = q[b];
            b++;
            if(k == 0 || aux.first + 1 == aux.second) {
                for(i = aux.second - 1; i >= aux.first; i--) {
                    sol[i] = val;
                    val--;
                }
            }
            else {
                int med = (aux.first + aux.second) / 2;
                q[e++] = {aux.first, med};
                q[e++] = {med, aux.second};
                k -= 2;
            }
        }
        if(k > 0)
            cout << -1;
        else
           for(i = 0; i < n; i++)
              cout << sol[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}