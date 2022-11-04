#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 22

using namespace std;

string a, b;
string sol, cur;

int fr[10], aux[10];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j;
    ios::sync_with_stdio(false);
    cin >> a >> b;
    for(auto it : a) {
        fr[it - '0']++;
        aux[it - '0']++;
    }
    if(a.size() < b.size()) {
        sort(a.begin(), a.end(), greater<int>());
        for(auto it : a)
            cout << it;
        return 0;
    }
    for(j = b[0] - '0' - 1; j > 0; j--) {
        if(aux[j] > 0) {
            aux[j]--;
            sol.push_back(j + '0');
            break;
        }
    }
    if(sol.size()) {
        for(j = 9; j >= 0; j--) {
            while(aux[j]) {
                aux[j]--;
                sol.push_back(j + '0');
            }
        }
    }
    for(i = 0; i < b.size(); i++) {
        if(fr[b[i] - '0'] == 0)
            break;
        fr[b[i] - '0']--;
        cur.push_back(b[i]);
        if(i + 1 < b.size()) {
            int d = -1;
            for(j = b[i + 1] - '0' - 1; j >= 0; j--) {
                if(fr[j] > 0) {
                    cur.push_back(j + '0');
                    d = j;
                    break;
                }
            }
            if(d > -1) {
                fr[d]--;
                for(j = 9; j >= 0; j--) {
                    for(int k = 0; k < fr[j]; k++) {
                        cur.push_back(j + '0');
                    }
                }
                fr[d]++;
                if(sol < cur)
                    sol = cur;
            }
            while(cur.size() > i + 1) {
                cur.pop_back();
            }
        }
        else {
            sol = cur;
        }
    }
    cout << sol;
    //cin.close();
    //cout.close();
    return 0;
}