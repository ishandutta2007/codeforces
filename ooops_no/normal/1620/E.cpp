#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int N = 5e5 + 10;
int po[20][N];

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    vector<pair<int,int>> a(q);
    for (int i = 0; i < q; i++){
        int t;
        cin >> t;
        if (t == 1){
            cin >> a[i].first;
            a[i].second = -1;
        }
        else{
            cin >> a[i].first >> a[i].second;
        }
    }
    vector<int> last(N, -1);
    for (int i = q - 1; i >= 0; i--){
        if (a[i].second == -1){
            if (last[a[i].first] == -1){
                po[0][i] = i;
            }
            else{
                po[0][i] = last[a[i].first];
            }
        }
        else{
            if (last[a[i].second] == -1){
                po[0][i] = i;
            }
            else{
                po[0][i] = last[a[i].second];
            }
            last[a[i].first] = i;
        }
    }
    for (int i = 1; i < 20; i++){
        for (int j = 0; j < N; j++){
            po[i][j] = po[i - 1][po[i - 1][j]];
        }
    }
    for (int i = 0; i < q; i++){
        int j = po[19][i];
        if (a[i].second == -1){
            if (a[j].second == -1){
                cout << a[j].first << ' ';
            }
            else{
                cout << a[j].second << ' ';
            }
        }
    }
    cout << endl;
    return 0;
}