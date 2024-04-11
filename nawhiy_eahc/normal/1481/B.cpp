#include <bits/stdc++.h>

using namespace std;

int h[102];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i=1;i<=n;i++) cin >> h[i];
        h[n+1] = -1;

        if(k > 10000) cout << "-1\n";
        else{
            for(int i=1;i<=k;i++){
                int change = -1;
                for(int j=1;j<=n;j++){
                    if(h[j] < h[j+1]){
                        change = j;
                        h[j]++;
                        break;
                    }
                }
                if(i == k) cout << change << "\n";
            }
        }
    }
}