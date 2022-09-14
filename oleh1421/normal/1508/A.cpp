#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
#define __int128_t ll
const int N=100010;
int cntA[2],cntB[2],cntC[2];
void solve(){
    int n;cin>>n;
    string A,B,C;cin>>A>>B>>C;
    for (int i=0;i<2;i++){
        cntA[i]=cntB[i]=cntC[i]=0;
    }
    for (auto i:A){
        cntA[i-'0']++;
    }
    for (auto i:B){
        cntB[i-'0']++;
    }
    for (auto i:C){
        cntC[i-'0']++;
    }
    string x,y;
    int c;
    if (cntA[0]>=n && cntB[0]>=n){
        x=A,y=B;
        c=0;
    } else if (cntA[0]>=n && cntC[0]>=n){
        x=A,y=C;
        c=0;
    } else if (cntB[0]>=n && cntC[0]>=n){
        x=B,y=C;
        c=0;
    } else if (cntA[1]>=n && cntB[1]>=n){
        x=A,y=B;
        c=1;
    } else if (cntA[1]>=n && cntC[1]>=n){
        x=A,y=C;
        c=1;
    } else {
        x=B,y=C;
        c=1;
    }
//    cout<<x<<" "<<y<<" "<<c<<endl;
    string ans="";
    int i=0,j=0;
    n*=2;
    while (i<n || j<n){
        int cnt=0;
        while (i<n && x[i]-'0'!=c){
            ans+=char((c+1)%2+'0');
            i++;
        }
        while (j<n && y[j]-'0'!=c){
            ans+=char((c+1)%2+'0');
            j++;
        }
        if (i<n || j<n) ans+=char(c+'0');
        i++;
        j++;
    }
    cout<<ans<<endl;


}

int32_t main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
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