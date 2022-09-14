//#pragma GCC optimize ("trapv")
//#pragma GCC opitmize ("unroll-loops")

#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=35;
int dp[7*15+1][4*15+1][16][16];
string get_max(string a,string b){
    if (a[0]=='-') return b;
    if (b[0]=='-') return a;
    if (a.size()<b.size()) return b;
    if (a.size()>b.size()) return a;
    return max(a,b);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    for (int i=0;i<n;i++){
        char ch;cin>>ch;
        int x=(ch-'0');
        a+=(x/2)+(x/4)+(x/8);
        b+=(x/3)+(x/9);
        c+=(x/5);
        d+=(x/7);
    }
    for (int i=0;i<=a;i++){
        for (int j=0;j<=b;j++){
            for (int t=0;t<=c;t++){
                for (int g=0;g<=d;g++){
                    dp[i][j][t][g]=-1000000001;
                }
            }
        }
    }
//    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    dp[0][0][0][0]=0;
    for (int i=0;i<=a;i++){
        for (int j=0;j<=b;j++){
            for (int t=0;t<=c;t++){
                for (int g=0;g<=d;g++){
                    for (int cur=2;cur<10;cur++){
                        int nxti=i+(cur/2)+(cur/4)+(cur/8);
                        int nxtj=j+(cur/3)+(cur/9);
                        int nxtt=t+(cur/5);

                        int nxtg=g+(cur/7);
                        if (nxti<=a && nxtj<=b && nxtt<=c && nxtg<=d) {
                            dp[nxti][nxtj][nxtt][nxtg]=max(dp[nxti][nxtj][nxtt][nxtg],dp[i][j][t][g]+1);
                        }
                    }
                }
            }
        }
    }
    string res="";
    int len=dp[a][b][c][d];
    while (len){
        int num=-1;
        for (int cur=9;cur>1;cur--){
            int nxti=a-(cur/2)-(cur/4)-(cur/8);
            int nxtj=b-(cur/3)-(cur/9);
            int nxtt=c-(cur/5);
            int nxtg=d-(cur/7);
            if (nxti>=0 && nxtj>=0 && nxtt>=0 && nxtg>=0) {
                if (dp[nxti][nxtj][nxtt][nxtg]+1==len){
                    num=cur;
                    a=nxti;
                    b=nxtj;
                    c=nxtt;
                    d=nxtg;
                    break;

                }
            }
        }
        len--;
        res+=char(num+'0');
    }
    cout<<res;
    return 0;
}

/*
3 - 4
*/