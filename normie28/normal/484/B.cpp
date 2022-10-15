#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define eb emplace_back
#define mp make_pair
 
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
const int M = 2e6 + 10;
 
int a[M];
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        a[x] = x;
    }
 
    int ans = 0;
    forn(i,M-1) a[i+1] = max(a[i+1], a[i]);
    forsn(i,1,M) if (a[i] == i) {
        for (int j = i; j < M; j += i) {
            int cand = max(i, a[j-1]);
            ans = max(ans, cand % i);
        }  
    }
    cout << ans << endl;
}