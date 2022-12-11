#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e6;
int l[MAXN+1];

int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    int n;
    cin >> n;
    int sk;
    int p = 1;
    for(int i = 0;i<n;i++){
        cin >> sk;
        for(int j = 0;j<sk;j++){
            l[p] = i+1;
            p++;
        }
    }
    int q;
    cin >> q;
    int ask;
    for(int i = 0;i<q;i++){
        cin >> ask;
        cout << l[ask] << "\n";
    }
    return 0;
}