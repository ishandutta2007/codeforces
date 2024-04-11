#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
#define int ll
const int N=1010;
char a[N][N];
int cnt[3];
int cnt1[3];
void solve(){
    int n;cin>>n;
    cnt[0]=cnt[1]=cnt[2]=cnt1[0]=cnt1[1]=cnt1[2]=0;
    int tot=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>a[i][j];
            if (a[i][j]=='X'){
                cnt[(i+j)%3]++;
                tot++;
            } else if (a[i][j]=='O'){
                cnt1[(i+j)%3]++;
                tot++;
            }
        }
    }

    int mn=-1,mn1=-1;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (i!=j && (cnt[i]+cnt1[j])*3<=tot){
                mn=i,mn1=j;
                break;
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;++j){
            if (a[i][j]=='X' && (i+j)%3==mn) a[i][j]='O';
            else if (a[i][j]=='O' && (i+j)%3==mn1) a[i][j]='X';
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}