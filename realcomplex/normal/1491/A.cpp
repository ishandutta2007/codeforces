#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
int a[N];
int c[2];

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
        c[a[i]] ++ ;
    }
    int t, p;
    for(int i = 1; i <= q; i ++ ){
        cin >> t >> p;
        if(t == 1){
            c[a[p]]--;
            a[p]^=1;
            c[a[p]]++;
        }
        else{
            if(c[1] >= p)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
    }
    return 0;
}