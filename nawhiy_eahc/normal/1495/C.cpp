#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int gar[502][502];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=m+1;j++){
                gar[i][j] = 0;
            }
        }

        for(int i=1;i<=n;i++){
            string s; cin >> s;
            for(int j=1;j<=m;j++){
                if(s[j-1] == '.') gar[i][j] = 0;
                else gar[i][j] = 1;
            }
        }
        bool flag;
        int p;
        if(n%3 == 0) p = n - 2;
        if(n%3 == 1) p = n;
        if(n%3 == 2) p = n - 1;
        for(int i=1;i<=p;i++){
            if(i%3 == 1){
                for(int j=1;j<=m;j++){
                    gar[i][j] = 1;
                }
                flag = true;
            }

            if(i%3 == 2){
                for(int j=1;j<=m;j++){
                    if(gar[i][j] && flag){
                        gar[i+1][j] = 1;
                        flag = false;
                    }
                }
            }

            if(i%3 == 0){
                for(int j=1;j<=m;j++){
                    if(gar[i][j] && flag){
                        gar[i-1][j] = 1;
                        flag = false;
                    }
                }

                if(flag) gar[i][1] = gar[i-1][1] = 1;
            }
        }

        if(n%3 == 0){
            for(int j=1;j<=m;j++){
                if(gar[n][j]) gar[n-1][j] = 1;
            }
        }


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(gar[i][j]) cout << "X";
                else cout << ".";
            }
            cout << "\n";
        }
    }
}