#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
vector<int> A[N];

int P[N];
ll Q[N];

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n, m;
    cin >> n >> m;
    int x;
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            cin >> x;
            A[i].push_back(x);
        }
    }
    ll res = 0;
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            res += P[A[i][j]] * 1ll * i - Q[A[i][j]];
            P[A[i][j]] ++ ;
            Q[A[i][j]] += i;

        }
    }
    for(int i = 1; i < N; i ++ ){
        P[i] = Q[i] = 0;
    }
    for(int j = 0 ; j < m ; j ++ ){
        for(int i = 0 ; i < n; i ++ ){
            res += P[A[i][j]] * 1ll * j - Q[A[i][j]];
            P[A[i][j]] ++ ;
            Q[A[i][j]] += j;
        }
    }
    cout << res << "\n";
    return 0;
}