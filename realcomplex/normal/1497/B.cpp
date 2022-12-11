#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
int cnt[N];

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        int n, m;
        cin >> n >> m;
        int a;
        for(int j = 0 ; j < m ; j ++ )
            cnt[j] = 0;
        for(int i = 1; i <= n; i ++ ){
            cin >> a;
            cnt[a % m] ++ ;
        }
        int sol = 0;
        int lf, rf;
        for(int j = 0 ;j < m ; j ++ ){
            if(2 * j == m){
                if(cnt[j] > 0)
                    sol ++ ;
            }
            else if(2 * j < m){
                if(j == 0){
                    sol += min(cnt[j],1);
                }
                else{
                    lf = cnt[j];
                    rf = cnt[m - j];
                    if(lf > rf) swap(lf, rf);
                    if(rf == 0) continue;
                    if(rf-lf<=1){
                        sol += 1;
                    }
                    else{
                        sol += (rf-lf);
                    }
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}