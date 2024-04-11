#include <bits/stdc++.h>

using namespace std;
int t[5001][5001];
int so[100001];
int melyik[100001];
int milyen[100001];
bool sor[5001];
bool oszlop[5001];
int main()
{
    //ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i=1; i<k+1; i++){
        cin >> so[i] >> melyik[i] >> milyen[i];
    }
    reverse(so+1, so+k+1);
    reverse(melyik+1, melyik+k+1);
    reverse(milyen+1, milyen+k+1);

    for (int i=1; i<k+1; i++){
        if (so[i]==1){
            if (sor[melyik[i]]==false){
                for (int j=1; j<=m; j++){
                    if (t[melyik[i]][j]==0){
                        t[melyik[i]][j]=milyen[i];
                    }
                }
                sor[melyik[i]]=true;
            }
        } else {
            if (oszlop[melyik[i]]==false){
                for (int j=1; j<=n; j++){
                    if (t[j][melyik[i]]==0)    {
                        t[j][melyik[i]]=milyen[i];
                    }
                }
                oszlop[melyik[i]]=true;
            }
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<m+1; j++){
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}