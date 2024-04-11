#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("in.txt","r",stdin);
    int n,d;
    cin >> n >> d;
    d*=100;
    int l,r;
    int ans = 0;
    bool can = false;
    for(int j = 0;j<n;j++){
        cin >> l >> r;
        int tek = (l*100)+r;
        if(tek>d)continue;
        can = true;
        ans = max(ans,(100-r)%100);
    }
    cout << ((can == false) ? -1 : ans);
    return 0;
}