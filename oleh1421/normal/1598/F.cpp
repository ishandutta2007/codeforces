//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const ll mod=1000000007;
const int S=400001;
const int N=20;
int cnt[N][S];
int mn[N];
int sum[N];
int dp[(1<<N)][2];
void solve(){
    int n;cin>>n;
    for (int i=0;i<n;i++){
        string s;cin>>s;
        vector<int>v;
        mn[i]=0;
        sum[i]=0;

        for (int j=0;j<s.size();j++){
            if (s[j]=='(') sum[i]++;
            else sum[i]--;
            mn[i]=min(mn[i],sum[i]);
            v.push_back(sum[i]);
        }
//        cout<<mn[i]<<endl;
        int mn1=0;
        for (int j:v){
            if (j<=mn1){
                mn1=j;
                cnt[i][mn1-mn[i]]++;
            }
        }
//        cout<<cnt[i][0]<<endl;
    }
    for (int mask=0;mask<(1<<n);mask++){
        dp[mask][0]=dp[mask][1]=-S;
    }
    dp[0][0]=0;
    for (int mask=0;mask<(1<<n);mask++){
        for (int was=0;was<2;was++){
            int ss=0;
            for (int i=0;i<n;i++){
                if (mask&(1<<i)) ss+=sum[i];
            }
            for (int i=0;i<n;i++){
                if (mask&(1<<i)) continue;
                if (was) dp[mask^(1<<i)][1]=max(dp[mask^(1<<i)][1],dp[mask][was]);
                else {
                    int nxt=((mn[i]+ss)<0);
                    int val=dp[mask][was];
//                    ss+x=0
//                    x=-ss
                    if (mn[i]+ss<=0) val+=cnt[i][-ss-mn[i]];
                    dp[mask^(1<<i)][nxt]=max(dp[mask^(1<<i)][nxt],val);
                }
            }

        }
    }
    cout<<max(dp[(1<<n)-1][0],dp[(1<<n)-1][1])<<endl;

}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}

//a b c
//a (b+c)/2 (b+c)/2
//(2*a+b+c)/4 (2*a+b+c)/4 (b+c)/2
//(2*a+b+c)/4 (2*a+3*b+3*c)/8 (2*a+3*b+3*c)/8
//(6*a+5*b+5*c)/16 (6*a+5*b+5*c)/16
///C=MEX(A)^B + MEX(B)^A
///MEX(C)=MEX(A)^MEX(B)
///A - DONE
//a b c
//a b c d

//0 1 2 3

//0 1 2 3
//0 1 2 3
//
//1+1+1+1+

/**
1 3
0.0 0.1 0.5 0.2
**/