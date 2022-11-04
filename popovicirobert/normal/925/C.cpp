#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

vector <int> id[60];

ll b[MAXN + 1];
int fr[60];

vector <ll> sol;

inline void del(int bit) {
    int pos = id[bit].back();
    id[bit].pop_back();
    sol.push_back(b[pos]);
    for(int i = 0; i < 60; i++) {
        if(b[pos] & (1LL << i))
            fr[i]--;
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> b[i];
        int bit = 0;
        for(j = 0; j < 60; j++) {
            if(b[i] & (1LL << j)) {
                fr[j]++;
                bit = j;
            }
        }
        id[bit].push_back(i);
    }
    while(n > 0) {
        n--;
        int mx = 0, pos;
        for(i = 0; i < 60; i++) {
            if(fr[i] % 2 == 1 && mx < (int) id[i].size()) {
                mx = (int) id[i].size();
                pos = i;
            }
        }
        //printf("%d %d\n" ,mx,pos);
        if(mx == 0) {
            cout << "No";
            return 0;
        }
        del(pos);
    }
    cout << "Yes" << "\n";
    reverse(sol.begin(), sol.end());
    for(auto it : sol) {
        cout << it << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}