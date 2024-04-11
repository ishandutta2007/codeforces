#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e12

void open(){
    freopen("in.txt","r",stdin);
    //freopen("01.out","w",stdout);
}

main(){
   // open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin >> n >> k;
    if(k>n){
        cout << -1;
        exit(0);
    }
    int l[n];
    for(int i = 0;i<n;i++) cin >> l[i];
    sort(l,l+n);
    cout << l[n-k] << " " << l[n-k];
    return 0;
}