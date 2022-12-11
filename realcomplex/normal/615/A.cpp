#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair

int cnt[105];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    int k;
    int val;
    for(int i = 0;i<n;i++){
        cin >> k;
        for(int x = 0;x<k;x++){
            cin >> val;
            cnt[val]++;
        }
    }
    for(int j = 1;j<=m;j++){
        if(cnt[j] == 0){
            cout << "NO";
            exit(0);
        }
    }
    cout << "YES";
    return 0;
}