#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
bool a[2020][2020];
int row[2020][2020];
int col[2020][2020];
int res_row[2020][2020];
int res_col[2020][2020];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;cin>>c;
            a[i][j]=(c=='B');
            row[i][j]=row[i][j-1]+a[i][j];
            col[j][i]=col[j][i-1]+a[i][j];
        }
    }
    int maxx=0;

    for (int i=1;i<=n-k+1;i++){
        for (int j=1;j<=n-k+1;j++){
            if (i==1 || j==1){
                int cnt=0;
                for (int t=i;t<=i+k-1;t++){
                    if (row[t][n] && row[t][n]==row[t][j+k-1]-row[t][j-1]) cnt++;
                }
                res_row[i][j]=cnt;
                for (int t=j;t<=j+k-1;t++){
                    if (col[t][n] && col[t][n]==col[t][i+k-1]-col[t][i-1]) cnt++;
                }
                res_col[i][j]=cnt-res_row[i][j];
            } else {
                res_row[i][j]=res_row[i-1][j];
                res_row[i][j]-=(row[i-1][n] && row[i-1][n]==row[i-1][j+k-1]-row[i-1][j-1]);
                res_row[i][j]+=(row[i-1+k][n] && row[i-1+k][n]==row[i-1+k][j+k-1]-row[i-1+k][j-1]);
                res_col[i][j]=res_col[i][j-1];
                res_col[i][j]-=(col[j-1][n] && col[j-1][n]==col[j-1][i+k-1]-col[j-1][i-1]);
                res_col[i][j]+=(col[j-1+k][n] && col[j-1+k][n]==col[j-1+k][i+k-1]-col[j-1+k][i-1]);
            }
            maxx=max(maxx,res_row[i][j]+res_col[i][j]);
        }
    }
    for (int i=1;i<=n;i++){
        maxx+=(row[i][n]==0);
        maxx+=(col[i][n]==0);
    }
    cout<<maxx;

    return 0;
}