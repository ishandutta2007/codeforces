#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
int gcd(int a,int b){
    if (a==0) return b;
    if (b==0) return a;
    return __gcd(a,b);
}
int dp[11][11][11][11];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;cin>>s;
    for (int x=0;x<10;x++){
        for (int y=0;y<10;y++){
            for (int i=0;i<10;i++) for (int j=0;j<10;j++) dp[x][y][i][j]=1000000001;
            for (int i=0;i<10;i++) dp[x][y][i][(x+i)%10]=1,dp[x][y][i][(y+i)%10]=1;
            int g=gcd(10,gcd(x,y));
            for (int k=0;k<10;k+=g){
                for (int i=0;i<10;i+=g){
                    for (int j=0;j<10;j+=g){
                        dp[x][y][i][j]=min(dp[x][y][i][j],dp[x][y][i][k]+dp[x][y][k][j]);
                    }
                }
            }
        }
    }
    for (int x=0;x<10;x++){
        for (int y=0;y<10;y++){
            int cur=0;
            bool ok=true;
            int g=gcd(10,gcd(x,y));
            for (int i=1;i<s.size();i++){
                cur+=dp[x][y][s[i-1]-'0'][s[i]-'0']-1;
                if ((s[i]-'0')%g) ok=false;
            }
            if (ok) cout<<cur<<" ";
            else cout<<-1<<" ";
            //cout<<cur<<" ";
        }
        cout<<endl;
    }
    return 0;
}