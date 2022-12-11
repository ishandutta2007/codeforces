#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int M = (int)1e6 + 10;
int cntu[M], cntd[M];

void solve(){
    string t;
    cin >> t;
    int n=t.size();
    int m = n * 2;
    for(int i = 0 ; i <= m ; i ++) {
        cntu[i]=cntd[i]=0;
    }
    int cnt = n;
    for(char x : t){
        if(x == '0') {
            cntu[cnt]++;
            cnt ++ ;
        }
        else{
            cntd[cnt]++;
            cnt -- ;
        }
    }
    int cur = n;
    while(cntu[cur] > 0 || cntd[cur] > 0){
        if(cntu[cur] > 0 && (cntd[cur+1] > 0 || cntd[cur] == 0)){
            cntu[cur]--;
            cur++;
            cout << 0;
        }
        else{
            cntd[cur]--;
            cur -- ;
            cout << 1;
        }
    }
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ )
        solve();
    return 0;
}