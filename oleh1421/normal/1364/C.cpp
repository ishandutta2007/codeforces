//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=100010;
int a[N];
int b[N];
bool used[N*3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) b[i]=-1;
    for (int i=2;i<=n;i++){
        if (a[i]>a[i-1]) b[i]=a[i-1];
    }
    for (int i=1;i<=n;i++){
        used[a[i]]=true;
    }
    int cur=0;
    for (int i=1;i<=n;i++){
        if (b[i]==-1){
            while (used[cur]) cur++;
            b[i]=cur;
            cur++;
        }
    }
    for (int i=1;i<=n;i++) cout<<b[i]<<" ";
    cout<<endl;
    return 0;
}
/*
3 4
1 3
5
9 2 7 7
6 1 0 9
4 7 4 6
*/