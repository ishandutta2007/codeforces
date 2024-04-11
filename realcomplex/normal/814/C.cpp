#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int AL = 26;
const int N = 1505;
int res[AL][N];

int main(){
    fastIO;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int is;
    int sz;
    for(int z = 0 ; z < AL; z ++ ){
        for(int i = 0; i < n; i ++ ){
            is = 0;
            for(int j = i; j < n; j ++ ){
                is += (s[j] - 'a' == z);
                sz = j - i + 1;
                res[z][sz - is] = max(res[z][sz - is], sz);
            }
        }
    }
    for(int i = 0 ; i < AL ; i ++ )
        for(int j = 1; j < N; j ++ )
            res[i][j] = max(res[i][j], res[i][j-1]);
    int q;
    cin >> q;
    char f;
    int k;
    for(int i = 0 ; i < q; i ++ ){
        cin >> k >> f;
        cout << res[f - 'a'][k] << "\n";
    }
    return 0;
}