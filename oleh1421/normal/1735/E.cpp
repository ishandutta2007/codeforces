#include <bits/stdc++.h>
#define endl '\n'
#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef long double ld;
const ll inf=1e18;
const int N=300010;
int d[2][N];
int D[2][N];
int n;
bool check(int dist,int sw){
    for (int i=0;i<=n+1;i++) d[0][i]=D[0][i],d[1][i]=D[1][i];
    int i=n,j=n;

    vector<int>h;
    int p1=0;
    int p2=dist;
    while (i>=1 && j>=1){
        if (d[0][i]>d[1][j]){
            h.push_back(p1+d[0][i]);
            int x=abs(d[0][i]-dist);
            int pos=lower_bound(d[1]+1,d[1]+n+1,x)-d[1];
            if (d[1][pos]!=x) return false;
            if (abs(h.back()-p2)!=d[1][pos]) exit(1);
            d[1][pos]--;
            d[0][i]--;
            i--;
        } else {
            h.push_back(p2-d[1][j]);
            int x=abs(d[1][j]-dist);

            int pos=lower_bound(d[0]+1,d[0]+n+1,x)-d[0];
            if (d[0][pos]!=x) return false;
            if (abs(h.back()-p1)!=d[0][pos]) exit(1);
            d[0][pos]--;
            d[1][j]--;
            j--;

        }
        while (i>=1 && d[0][i]%2) i--;
        while (j>=1 && d[1][j]%2) j--;
    }
    if (h.size()!=n) return false;
//    for (int i=1;i<=n;i++){
//        if (d[0][i]%2==0) exit(1);
//        if (d[1][i]%2==0) exit(1);
//    }
    int mn=0;
    for (int x:h) mn=min(mn,x);
    p1-=mn;
    p2-=mn;
    for (int &x:h) x-=mn;
    p1/=2;
    p2/=2;
    for (int &x:h) x/=2;
    cout<<"YES\n";
    for (int i:h) cout<<i<<" ";
    cout<<'\n';
    if (sw) swap(p1,p2);
    cout<<p1<<" "<<p2<<'\n';
    for (int i=1;i<=n;i++){
        d[0][i]=abs(p1-h[i-1]);
        d[1][i]=abs(p2-h[i-1]);
    }
    sort(d[0]+1,d[0]+n+1);
    sort(d[1]+1,d[1]+n+1);

    for (int i=1;i<=n;i++){
        if (d[0][i]*2!=D[0][i]) {
            exit(1);
        }
    }
//    for (int i=1;i<=n;i++){
//        if (d[1][i]*2!=D[1][i]) exit(1);
//    }
    return true;


}
void solve(){
    cin>>n;
    for (int i=0;i<2;i++){
        for (int j=1;j<=n;j++) cin>>D[i][j],D[i][j]*=2;
    }
    D[0][0]=D[1][0]=-1;
    D[0][n+1]=D[1][n+1]=-1;
    sort(D[0]+1,D[0]+n+1);
    sort(D[1]+1,D[1]+n+1);
    vector<int>C;
    for (int i=1;i<=n;i++){
        C.push_back(D[0][1]+D[1][i]);
        C.push_back(abs(D[0][1]-D[1][i]));
    }


    for (int x:C){
        if (check(x,0)) return;
    }

    cout<<"NO\n";



}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}