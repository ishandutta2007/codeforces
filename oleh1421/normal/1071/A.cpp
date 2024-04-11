#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
int a[300001];
int s[300001];
int cnt[2];
bool used[300001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b;cin>>a>>b;
    int x=0;
    while (x*(x+1)<=a+b+a+b) x++;x--;
    int n=0;
    for (int i=x;i>=1;i--){
        if (i<=a){
            a-=i;
            used[i]=true;
            n++;
        }
    }
    cout<<n<<endl;
    for (int i=1;i<=x;i++){
        if (used[i]) cout<<i<<" ";
    }
    cout<<endl<<x-n<<endl;
    for (int i=1;i<=x;i++){
        if (!used[i]) cout<<i<<" ";
    }
    return 0;
}
/*
7
0110010
1 2
1 3
1 4
2 5
2 6
3 7
*/