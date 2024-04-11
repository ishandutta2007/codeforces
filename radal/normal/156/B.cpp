#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=5e5+20,mod = 1e9+7,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
pair<char,int> q[N];
int ng[N],ps[N],f[N];
int n,m,neg,pos;
int main(){
    cin >> n >> m;
    rep(i,1,n+1){
        string s;
        cin >> s;
        int k = 0,sz = s.size();
        rep(i,1,sz){
            k*=10;
            k+=s[i]-'0';
        }
        q[i] = {s[0],k};
        if (s[0] == '-'){
            ps[k]++;
            pos++;
        }
        else{
            ng[k]++;
            neg++;
        }
    }
    bool fl = 0;
    rep(i,1,n+1){
        if (ng[i] > m) f[i] = 1;
        if (ps[i] > m){
            f[i] = -1;
            fl = 1;
        }
        if (ng[i]+pos-ps[i] != m) f[i] = 1;
        if (ng[i] > n-m) f[i] = -1;
        if (ps[i] > n-m) f[i] = 1;
    }
    if (fl) rep(i,1,n+1) if (f[i] != -1) f[i] = 1;
    int cnt = 0;
    rep(i,1,n+1) if (f[i] == 1) cnt++;
    if (cnt == n-1){
        rep(i,1,n+1) if (f[i] != 1) f[i] = -1;
    }
 /*   cnt = 0;
    int cnt2 = 0;
    rep(i,1,n+1){
        int u = q[i].Y;
        if (f[u] == 0){
            cnt++;
            continue;
        }
        if ((f[u] == 1 && q[i].X == '+') || (f[u] == -1 && q[i].X == '-')) continue;
        cnt2++;
    }
    if (m-cnt2 == cnt){
        rep(i,1,n+1){
            if (f[q[i].Y] == 0){
                if(q[i].X == '-') f[q[i].Y] = 1;
                else{
                    f[q[i].Y] = -1;
                    fl = 1;
                }
            }
        }
    }
    if ((n-m)-(n-cnt-cnt2) == cnt){
        rep(i,1,n+1){
            if (f[q[i].Y] == 0){ 
                if(q[i].X == '+') f[q[i].Y] = 1;
                else{ 
                    f[q[i].Y] = -1;
                    fl = 1;
                }
            }
        }
    }*/
    if (fl) rep(i,1,n+1) if (f[i] != -1) f[i] = 1;
    rep(i,1,n+1){ 
        int u = q[i].Y;
        if (f[u] == 0){
            cout << "Not defined" << endl;
            continue;
        }
        if ((f[u] == 1 && q[i].X == '+') || (f[u] == -1 && q[i].X == '-')){
            cout << "Lie" << endl;
            continue;
        }
        cout << "Truth" << endl;
    }

}