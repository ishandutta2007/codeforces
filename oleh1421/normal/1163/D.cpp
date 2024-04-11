#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
///#define int long long
using namespace std;
const int N=500000;
const int L=25;
int dp[1010][55][55];
int toA[55][30];

int toB[55][30];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s,a,b;cin>>s>>a>>b;
    int a1=0;
    for (int i=1;i<a.size();i++){
        bool ok=true;
        for (int j=i;j<a.size();j++){
            if (a[j]!=a[j-i]){
                ok=false;
                break;
            }
        }
        if (ok){
            a1=(int)a.size()-i;
            break;
        }
    }
    int b1=0;
    for (int i=1;i<b.size();i++){
        bool ok=true;
        for (int j=i;j<b.size();j++){
            if (b[j]!=b[j-i]){
                ok=false;
                break;
            }
        }
        if (ok){
            b1=(int)b.size()-i;
            break;
        }
    }
    for (int i=0;i<a.size();i++){
        for (int j=0;j<='z'-'a';j++){
            string cur="";
            for (int t=0;t<i;t++) cur+=a[t];
            cur+=char(j+int('a'));
            toA[i][j]=0;
            for (int t=0;t<cur.size();t++){
                bool ok=true;
                for (int g=t;g<cur.size();g++){
                    if (cur[g]!=a[g-t]){
                        ok=false;
                        break;
                    }
                }
                if (ok){
                    toA[i][j]=(int)cur.size()-t;
                    break;
                }
            }
        }
    }
    for (int i=0;i<=b.size();i++){
        for (int j=0;j<='z'-'a';j++){
            string cur="";
            for (int t=0;t<i;t++) cur+=b[t];
            cur+=char(j+int('a'));
            toB[i][j]=0;
            for (int t=0;t<cur.size();t++){
                bool ok=true;
                for (int g=t;g<cur.size();g++){
                    if (cur[g]!=b[g-t]){
                        ok=false;
                        break;
                    }
                }
                if (ok){
                    toB[i][j]=(int)cur.size()-t;
                    break;
                }
            }
        }
    }
    for (int i=0;i<=1000;i++) for (int j=0;j<=50;j++) for (int t=0;t<=50;t++) dp[i][j][t]=-2000000;
    dp[0][0][0]=0;
    for (int i=0;i<s.size();i++){
        for (int prefA=0;prefA<a.size();prefA++){
            for (int prefB=0;prefB<b.size();prefB++){
                for (int c=0;c<='z'-'a';c++){
                    if (char(int(c)+int('a'))==s[i] || s[i]=='*'){
                        int nxtA=toA[prefA][c];
                        int nxtB=toB[prefB][c];
                        int cur=dp[i][prefA][prefB];
                        if (nxtA==(int)a.size()){
                            nxtA=a1;
                            cur++;
                        }
                        if (nxtB==(int)b.size()){
                            nxtB=b1;
                            cur--;
                        }
                        dp[i+1][nxtA][nxtB]=max(dp[i+1][nxtA][nxtB],cur);
                    }
                }
            }
        }
    }
    int maxx=-20000000;
    for (int prefA=0;prefA<a.size();prefA++){
        for (int prefB=0;prefB<b.size();prefB++){
            maxx=max(maxx,dp[(int)s.size()][prefA][prefB]);
        }
    }
    cout<<maxx;
    return 0;
}