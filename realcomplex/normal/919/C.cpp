#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pair<int,int> pii
#define abs(a) ((a<0) ? -a : a)
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);

#define TEST freopen("in.txt","r",stdin);int q;cin>>q;while(q--)Solution()

/*******************************/

void Solution(){
    int n,m,k;
    cin >> n >> m >> k;
    if(k==1){
        int cnt = 0;
        char v;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cin >> v;
                cnt += (v=='.');
            }
        }
        cout << cnt <<"\n";
        return;
    }
    int conf[n][m];
    char u;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++){
            cin >> u;
            conf[i][j]=(u=='.');
        }

    int r = 0;
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(conf[i][j]==0)r=0;
            else{
                r++;
                if(r>=k)ans++;
            }
        }
        r=0;
    }
    r = 0;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(conf[j][i]==0)r=0;
            else{
                r++;
                if(r>=k)ans++;
            }
        }
        r=0;
    }
    cout << ans << "\n";
}

/*******************************/

int main(){
    fastIO;
    //TEST;
    Solution();
    return 0;
}