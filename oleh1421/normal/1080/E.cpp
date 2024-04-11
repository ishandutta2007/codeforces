//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const ll mod=1000000007;
const int N=510;
int a[N][N];
int cnt[N][26];
int s[N];
ll H[N];
ll mult[26];
int get(vector<ll>v){
//    cout<<v.size()<<endl;
//    for (int i:v) cout<<i<<" ";
//    cout<<endl;
    vector<int>d1(v.size(),0);
    int l=-1,r=-1;
    for (int i=0;i<v.size();i++){
        int k=0;
        if (i<=r){
            k=min(r-i,d1[r+l-i]);
        }
        while (i+k+1<v.size() && i-k-1>=0 && v[i-k-1]==v[i+k+1]) k++;
        if (i+k>r){
            l=i-k;
            r=i+k;
        }
        d1[i]=k;
    }
    l=r=-1;
    vector<int>d2(v.size(),0);
    for (int i=0;i<v.size();i++){
        int k=0;
        if (i<r){
            k=min(r-i,d2[r+l-i-1]);
        }
        while (i+k+1<v.size() && i-k>=0 && v[i-k]==v[i+k+1]) k++;
        if (i+k>r){
            l=i-k+1;
            r=i+k;
        }
        d2[i]=k;
    }
    int res=0;
    for (int i:d1) res+=i+1;
    for (int i:d2) res+=i;
    return res;
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[j][i]=(c-'a');
        }
    }
    swap(n,m);
    mult[0]=1;
    for (int i=1;i<26;i++) mult[i]=(mult[i-1]*503ll)%mod;
//    cout<<mult[1]<<endl;
    ll res=0ll;
    for (int l=1;l<=n;l++){
        for (int i=1;i<=m;i++){
            H[i]=0;
            s[i]=0;
            for (int j=0;j<26;j++) cnt[i][j]=0;
        }
        for (int r=l;r<=n;r++){
            for (int i=1;i<=m;i++){
                s[i]-=cnt[i][a[r][i]]%2;
                cnt[i][a[r][i]]++;
                s[i]+=cnt[i][a[r][i]]%2;
                H[i]+=mult[a[r][i]];
            }
            vector<ll>v;
            for (int i=1;i<=m;i++){
                if (s[i]<=1) v.push_back(H[i]);
                else {
                    res+=get(v);
                    v.clear();
                }
            }
            res+=get(v);
            v.clear();
        }
    }
    cout<<res<<endl;
}
///find any 2 coprime numbers
int32_t main()
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