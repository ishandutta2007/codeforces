#include <bits/stdc++.h>

using namespace std;

int lef[300002], rig[300002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        lef[0] = 0;
        for(int i=1;i<=n;i++){
            if(s[i-1] == 'L'){
                if(i >= 2 && lef[i-1] == 0) lef[i] = lef[i-2] + 2;
                else lef[i] = 1;
            }
            else lef[i] = 0;
        }

        rig[n] = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == 'R'){
                if(i <= n-2 && rig[i+1] == 0) rig[i] = rig[i+2] + 2;
                else rig[i] = 1;
            }
            else rig[i] = 0;
        }

        for(int i=0;i<=n;i++){
            cout << (lef[i] + rig[i] + 1) << " ";
        }
        cout << "\n";

    }
}