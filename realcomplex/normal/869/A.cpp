#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

int cnt[2000005];

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int x[n],y[n];
    for(int i = 0;i<n;i++){
        cin >> x[i];
        cnt[x[i]]++;
    }
    for(int i = 0;i<n;i++){
        cin >> y[i];
        cnt[y[i]]++;
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(x[i]^y[j] >= 2000005) continue;
            if(cnt[x[i]^y[j]] >= 1){
                ans++;
            }
        }
    }
    cout << ((ans%2 == 0) ? "Karen" : "Koyomi");
    return 0;
}