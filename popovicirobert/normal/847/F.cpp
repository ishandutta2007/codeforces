#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 100;

struct Candidate {
    int cnt;
    int last;
    int pos;
    bool operator <(const Candidate &other) const {
        if(cnt == other.cnt)
            return last > other.last;
        return cnt < other.cnt;
    }
}arr[MAXN + 1], aux[MAXN + 1];

int sol[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, k, a, id;
    ios::sync_with_stdio(false);
    cin >> n >> k >> m >> a;
    for(i = 1; i <= a; i++) {
        cin >> id;
        arr[id].cnt++;
        arr[id].last = i;
    }
    for(i = 1; i <= n; i++) {
        arr[i].pos = i;
    }
    m -= a;
    for(id = 1; id <= n; id++) {
        for(i = 1; i <= n; i++) {
            aux[i] = arr[i];
        }
        if(m == 0 && aux[id].cnt == 0) {
            sol[id] = 3;
            continue;
        }
        sort(aux + 1, aux + n + 1);
        int cnt = 0, votes = m, j = a + 1;
        i = n;
        while(i > 0) {
            if(aux[i].pos != id) {
                while(votes > 0 && aux[i] < arr[id]) {
                    aux[i].cnt++;
                    aux[i].last = j++;
                    votes--;
                }
                cnt += (arr[id] < aux[i]);
            }
            i--;
        }
        if(cnt < k && arr[id].cnt > 0) {
            sol[id] = 1;
        }
        else {
            for(i = 1; i <= n; i++) {
                aux[i] = arr[i];
                if(i == id) {
                    aux[i].cnt += m;
                    aux[i].last = a + m;
                }
            }
            sort(aux + 1, aux + n + 1);
            int pos;
            for(i = 1; i <= n; i++) {
                if(aux[i].pos == id)
                    pos = i;
            }
            if(pos <= n - k) {
                sol[id] = 3;
            }
            else {
                sol[id] = 2;
            }
        }
    }
    for(i = 1; i <= n; i++) {
        cout << sol[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}