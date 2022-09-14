//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=301010;
const int L=20;
const ll mod=1000000007;
const int inf=1e9;

void solve(int Case){
    int n,m,k;cin>>n>>m>>k;
    string a,b;cin>>a>>b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0,j=0;
    int A=0,B=0;
    string c="";
    while (i<a.size() && j<b.size()){
        int op=0;
        if (A==k) op=2;
        else if (B==k) op=1;
        else if (a[i]<b[j]) op=1;
        else op=2;
        if (op==1){
            c+=a[i++];
            A++;
            B=0;
        } else {
            c+=b[j++];
            B++;
            A=0;
        }
    }
    cout<<c<<endl;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
0 1
1 0 1 0 1 0 1 0 1 0 0 0
9 2 1 4 3 6 5 8 7 10 11 12

C(n-1,(n-1)/2)
 1 1 2 3 6 10 20 35 70 12
dp[i] = (i%2==1 ? dp[i-1]*2 : (dp[i-1]/4)*3);
**/