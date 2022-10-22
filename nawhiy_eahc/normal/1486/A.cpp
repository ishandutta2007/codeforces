#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        ll sum = 0;
        bool flag = false;
        for(int i=1;i<=n;i++){
            ll h; cin >> h;
            sum += h;

            if(sum < (i *(i-1))/2) flag = true;
        }

        if(!flag) printf("YES\n");
        else printf("NO\n");
    }
}