#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=510;
int a[N][N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    if (n==3){
        cout<<1<<" "<<3<<" "<<2<<endl;
        cout<<8<<" "<<4<<" "<<5<<endl;
        cout<<6<<" "<<7<<" "<<9<<endl;
        return 0;
    }
    if (n<=2){
        cout<<-1;
        return 0;
    }
    a[n-1][1]=n*n-1;
    a[n][1]=n*n-2;
    a[n][n]=n*n;
    int cur=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (!a[i][j]){
                a[i][j]=++cur;
            }
        }
    }
    if (n%2){
        swap(a[1][n-1],a[1][n]);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}