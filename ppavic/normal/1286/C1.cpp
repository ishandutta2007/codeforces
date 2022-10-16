#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int , int > pii;
typedef vector < int > vi;
typedef set < int > si;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int OFF = (1 << 18);

int n;
map < vector < int > , int > mp[3];

void query(int l,int r, int k){
    int ln = (r - l + 1);
    cout << "? " << l << " " << r << endl;
    for(int i = 0;i < ln * (ln + 1) / 2;i++){
        string tmp; cin >> tmp;
        vector < int > msk(26, 0);
        for(char c : tmp)
            msk[c - 'a']++;
        mp[k][msk]++;
    }
}

int main(){
    cin >> n;
    cout << "? " << 1 << " " << 1 << endl;
    char c; cin >> c;
    if(n == 1){
        cout << "! " << c << endl;
        return 0;
    }
    query(1, n, 0); query(2, n, 1);
    vector < int > cur(26, 0);
    cur[c - 'a']++;
    string ans; ans.PB(c);
    for(int i = 2;i <= n;i++){
        for(int j = 0;j < 26;j++){
            cur[j]++;
            if(mp[0][cur] != mp[1][cur]){
                ans.PB('a' + j); break;
            }
            cur[j]--;
        }
    }
    cout << "! " << ans << endl;
    return 0;
}