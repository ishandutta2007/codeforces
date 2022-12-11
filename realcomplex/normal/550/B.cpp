#include <bits/stdc++.h>

using namespace std;

typedef long double ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e12

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,l,r,x;
    cin >> n >> l >> r >> x;
    int dif[n];
    for(int j = 0;j<n;j++){
        cin >> dif[j];
    }
    sort(dif,dif+n);
    int ans = 0;
    int cnt;
    int s;
    int mz = 0;
    int li = 0;
    for(int j = 0;j<(1<<n);j++){
        cnt = 0;
        s = 0;
        mz = 1e9;
        li = 0;
        for(int i = 0;i<n;i++){
            if(j&(1<<i)){
                cnt++;
                s += dif[i];
                li = max(li,dif[i]);
                mz = min(mz,dif[i]);
            }
        }
        if(li-mz>=x&&s>=l&&s<=r&&cnt>=2){
            ans++;
        }
    }
    cout << ans;
    return 0;
}