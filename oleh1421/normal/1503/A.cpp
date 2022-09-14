#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define __int128_t ll
const int N=1500010;
int c[N];
int a[N];
int b[N];
void solve(){
    int n;cin>>n;
    int cnt=0;
    for (int i=1;i<=n;i++){
        char ch;cin>>ch;
        c[i]=(ch-'0');
        cnt+=c[i];
    }
    if (cnt%2){
        cout<<"NO\n";
        return;
    }
    int sumA=0;
    int sumB=0;
    string sA="";
    string sB="";
    int cur=0;
    for (int i=1;i<=n;i++){
        if (c[i]==1){
            cur++;
            if (cur<=cnt/2){
                sA+="(";
                sB+="(";
                sumA++;
                sumB++;
            } else {
                sA+=")";
                sB+=")";
                sumA--;
                sumB--;
            }
        } else if (sumA<sumB){
            sumA++;
            sA+="(";
            sumB--;
            sB+=")";
        } else {
            sumB++;
            sB+="(";
            sumA--;
            sA+=")";
        }
        if (sumA<0 || sumB<0){
            cout<<"NO\n";
            return;
        }
    }
    if (sumA || sumB){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    cout<<sA<<endl<<sB<<endl;
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
/**
1
5 5 100
4
5
4
3
1
OK
FAIL
OK
OK
OK
FAIL
OK

0 1 0 0 0

1
5 5 100
4
5
4
2
1

FAIL
FAIL
FAIL
OK
FAIL
OK
OK
FAIL
FAIL
FAIL
OK


! 10
**/