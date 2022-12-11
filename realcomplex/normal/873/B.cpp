#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e12

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

const int MAXN = 1e5+5;
int l[MAXN]; // 0<=1
int r[MAXN];// 0>1

void ini(){
    for(int j = 0;j<MAXN;j++){
        l[j] = 100000000;
        r[j] = 100000000;
    }
}

main(){
    //open();
    ini();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    char k[n];
    cin >> k;
    int cnt0 = 0,cnt1 = 0;
    int ans = 0;
    for(int j = 0;j<n;j++){
        if(k[j] != '0'){
            cnt1++;
        }
        else{
            cnt0++;
        }
        if(cnt1>cnt0){
            ans = max(ans,j-l[cnt1-cnt0]);
            l[cnt1-cnt0] = min(j,l[cnt1-cnt0]);
        }
        else if(cnt0>cnt1){
            ans = max(ans,j-r[cnt0-cnt1]);
            r[cnt0-cnt1] = min(j,r[cnt0-cnt1]);
        }
        else{
            ans = j+1;
        }
    }
    cout << ans;
    return 0;
}