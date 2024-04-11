//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int long long
using namespace std;
int a[1000001];
int b[1000001];
bool used[11];
bool ok(int a){
    for (int i=0;i<=9;i++) used[i]=false;
    while (a){
        if (used[a%10]) return false;
        used[a%10]=true;
        a/=10;
    }
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int l,r;cin>>l>>r;
    for (int i=l;i<=r;i++){
        if (ok(i)){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
/*
8
0
2 0
0 4 0 1
0 0 0 0 0 5 0 0

*/