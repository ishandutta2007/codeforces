#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin >> n >> k;
    pair<int,int>sk[n];
    for(int j = 0;j<n;j++){
        cin >> sk[j].fi;
        sk[j].se = j;
    }
    sort(sk,sk+n);
    if(k == 1){
        cout << sk[0].fi;
        exit(0);
    }
    for(int j = n-1;j>=0;j--){
        if(sk[j].se == n-1 || sk[j].se == 0 || k>2){
            cout << sk[j].fi;
            exit(0);
        }
    }
    return 0;
}