#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
template <class nmsl> inline void readInt(nmsl &x)
{
	x=0;
	char ch=getchar(), w=0;
	while(!isdigit(ch))w=(ch=='-'), ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
	x=w?-x:x;
}
int f(char c){
    if (int(c)>=int('a') && int(c)<=int('z')) return (c-'a');
    if (int(c)>=int('A') && int(c)<=int('Z')) return (c-'A')+('z'-'a')+1;
    return (c-'0')+('Z'-'A')+('z'-'a')+2;
}
ll cnt[101][101][101];
ll cnt1[11][65][65][65];
const long long mod=998244353;
map<string,bool>used;
ll prekalc[11];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        string s;cin>>s;
        if (!used[s]) {
            cnt[(int)s.size()][f(s[0])][f(s.back())]++;
            used[s]=true;
        }
        string s1=s;
        reverse(s1.begin(),s1.end());
        if (!used[s1]){
            cnt[(int)s.size()][f(s.back())][f(s[0])]++;
            used[s1]=true;
        }
    }


    for (int len=3;len<=10;len++){
    for (int i=0;i<=f('9');i++){
        for (int j=i;j<=f('9');j++){
            for (int t=j;t<=f('9');t++){
                cnt1[len][i][j][t]=0;
                for (int g=0;g<=f('9');g++){
                    cnt1[len][i][j][t]+=(cnt[len][i][g]*cnt[len][j][g]*cnt[len][t][g])%mod;
                    cnt1[len][i][j][t]%=mod;
                }
            }
        }
    }
    }
    for (int len=3;len<=10;len++){
    for (int i=0;i<=f('9');i++){
        for (int j=0;j<=f('9');j++){
            for (int t=0;t<=f('9');t++){
                int a=i;
                int b=j;
                int c=t;
                if (a>b) swap(a,b);
                if (b>c) swap(b,c);
                if (a>b) swap(a,b);
                cnt1[len][i][j][t]=cnt1[len][a][b][c];
            }
        }
    }
    }


    prekalc[0]=1;
    prekalc[1]=1;
    prekalc[2]=2;
    prekalc[3]=6;
    prekalc[4]=24;
    ll res=0;
    for (int i=3;i<=10;i++){
        for (int a1=0;a1<=f('9');a1++){
        for (int a3=a1;a3<=f('9');a3++){
        for (int a6=a3;a6<=f('9');a6++){
        for (int a8=a6;a8<=f('9');a8++){
             ll cur=1;
             cur*=cnt1[i][a1][a3][a8];
             cur%=mod;
             cur*=cnt1[i][a1][a3][a6];
             cur%=mod;
             cur*=cnt1[i][a1][a6][a8];
             cur%=mod;
             cur*=cnt1[i][a3][a6][a8];
             cur%=mod;
             ll fact=24;
             vector<int>v;
             int cnt=1;
             if (a3!=a1) {
                fact/=prekalc[cnt];
                cnt=1;
             } else {
                cnt++;
             }
             if (a6!=a3) {
                fact/=prekalc[cnt];
                cnt=1;
             } else {
                cnt++;
             }
             if (a8!=a6) {
                fact/=prekalc[cnt];
                cnt=1;
             } else {
                cnt++;
             }
             fact/=prekalc[cnt];
             res+=cur*fact*1ll;
             res%=mod;
        }
        }
        }
        }
    }
    cout<<res%mod;
    return 0;
}