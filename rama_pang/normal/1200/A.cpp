#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
#define ALL(vec) vec.begin(), vec.end()
#define db(x) cout << #x << " is " << x << endl
#define MEM(arr, val) memset(arr, val, sizeof(arr))
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define REP(i, s, e) for (int i = s; i <= e; i++)
#define REPR(i, s, e) for (int i = s; i >= e; i--)
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ii> vii;

ll N, M, V, E, A, B, C;
bool room[15];
int main() {
    IOS;
    cin >> N;
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'L') {
            for (int j=0; j<=9; j++) {
                if (room[j]) continue;
                room[j]=1;
                break;
            }
        } else if (s[i] == 'R') {
            for (int j=9; j>=0; j--) {
                if (room[j]) continue;
                room[j]=1;
                break;
            }
        } else {
            int a = s[i]-'0';
            room[a]=false;
        }
        
    }
    for (int i=0; i<=9; i++) {
        cout << room[i];
    }
    cout << endl;
}