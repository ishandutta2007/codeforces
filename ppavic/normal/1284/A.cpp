#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int , int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

string s[N], t[N];

int n, m;

int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++)
        cin >> s[i];
    for(int i = 0;i < m;i++)
        cin >> t[i];
    int Q; scanf("%d", &Q);
    for(;Q--;){
        int x; cin >> x;x--;
        cout << s[x % n] << t[x % m] << endl;

    }
    return 0;
}