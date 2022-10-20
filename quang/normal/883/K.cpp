#include <bits/stdc++.h>


using namespace std;

int const N = 2e5 + 5;

int n;

int s[N], g[N], pos[N], dl[N], dr[N], l[N], r[N];


bool inside(int p, int L, int R){
    return p >= L && p <= R;
}

main()
{
   // freopen("inp.txt", "r", stdin);

    cin >> n;
    int u, v;
    for(int i=1; i<=n; i++){
        cin >> s[i] >> g[i];
        l[i] = s[i];
        r[i] = s[i] + g[i];
    }

    dl[0] = 0;
    dr[0] = 1e9;

    for(int i=1; i<=n; i++){
        dl[i] = max(dl[i-1]-1, l[i]);
        dr[i] = min(dr[i-1]+1, r[i]);
        if(dl[i] > dr[i]){
            cout << -1;
            return 0;
        }
    }

    pos[n] = dr[n];

    for(int i=n-1; i>=1; i--){
        for(int j=1; j>=-1; j--){
            if(inside(pos[i+1]+j, dl[i], dr[i])){
                pos[i] = pos[i+1] + j;
                break;
            }
        }
    }
    long long ans = 0;

    for(int i=1; i<=n; i++){
        ans += pos[i] - l[i];
    }

    cout << ans << endl;
    for(int i=1; i<=n; i++)
        cout << pos[i] << " ";




}