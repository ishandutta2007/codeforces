#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 2020;

int n;
pair <int, int> a[N];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    for(int i  = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    a[n + 1] = make_pair(a[n].first + 1, n + 1);
    int sl = 1, st = 1;
    int flag = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i].first != a[i + 1].first) {
            if(st == 2 && sl * st >= 3) {
                flag = 2;
                break;
            }
            if(st == 2) sl *= 2;
            if(st >= 3) {
                flag = 3;
                break;
            }
            st = 1;
        } else st++;
    }
    if(!flag) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    st = 0, sl = 0;
    if(flag == 2) {
            int vt[2], d = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i].first == a[i + 1].first) vt[d++] = i;
                if(d >= 3) break;
        }
        for(int i = 1; i <= n; i++) cout << a[i].second << " " ;
        cout << endl;
        swap(a[vt[0]], a[vt[0] + 1]);
        for(int i = 1; i <= n; i++) cout << a[i].second << " " ;
        cout << endl;
        swap(a[vt[1]], a[vt[1] + 1]);
        for(int i = 1; i <= n; i++) cout << a[i].second << " " ;
        return 0;

    }
    if(flag == 3) {
        int vt;
        for(int i = 1; i <= n - 2; i++)
        if(a[i].first == a[i + 1].first && a[i].first == a[i + 2].first) {
            vt = i;
            break;
        }
        for(int i = 1; i <= 3; i++) {
            for(int j = 1; j <= n; j++) cout << a[j].second << " ";
            cout << endl;
            next_permutation(a + vt, a + vt + 3);
        }
    }
    return 0;
}