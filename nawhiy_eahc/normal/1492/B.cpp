#include <bits/stdc++.h>

using namespace std;

int p[100002], invp[100002];
bool used[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++){
            cin >> p[i];
            invp[p[i]] = i;
            used[i] = false;
        }

        int E = n, M = n;
        while(E){
            for(int i=invp[M];i<=E;i++){
                cout << p[i] << " ";
                used[p[i]] = true;
            }

            E = invp[M] - 1;

            for(int i=M;i>=0;i--){
                if(!used[i]){
                    M = i;
                    break;
                }
            }
        }

        cout << "\n";
    }
}