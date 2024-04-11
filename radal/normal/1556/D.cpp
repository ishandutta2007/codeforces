#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
//#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e4+20,mod = 1e9+7,inf=1e9,maxm = 1e6+1;
int a[N];
int main(){
    int n,k;
    cin >> n >> k;
    int x1,x2,x3;
    int y1,y2,y3;
    cout << "and" << ' ' << 1 <<  ' ' << 2 << endl;
    cin >> x1;
    a[1] = x1;
    a[2] = x1;
    cout << "and" << ' ' << 3 <<  ' ' << 2 << endl;
    cin >> x2;
    a[3] = x2;
    a[2] |= x2;
    cout << "and" << ' ' << 1 <<  ' ' << 3 << endl;
    cin >> x3;
    a[1] |= x3;
    a[3] |= x3;
    cout << "or" << ' ' << 1 <<  ' ' << 2 << endl;
    cin >> y1;
    cout << "or" << ' ' << 3 <<  ' ' << 2 << endl;
    cin >> y2;
    cout << "or" << ' ' << 1 <<  ' ' << 3 << endl;
    cin >> y3;
    rep(i,0,31){
        int j = (1 << i);
        if (a[1]&j) continue;
        if (!(y1&j) || !(y3&j)) continue;
        if (!(y2&j)) a[1] += j;
    }
    rep(i,0,31){
        int j = (1 << i);
        if (a[2]&j) continue;
        if(!(y1&j) || !(y2&j)) continue;
        if (!(y3&j)) a[2] += j;
    }
    rep(i,0,31){
        int j = (1 << i);
        if (a[3]&j) continue;
        if(!(y3&j) || !(y2&j)) continue;
        if (!(y1&j)) a[3] += j;
    }
    rep(i,4,n+1){
        int x,y;
        cout << "and" << ' ' << 1 << ' ' << i << endl;
        cin >> x;
        cout << "or" << ' ' << 1 << ' ' << i << endl;
        cin >> y;
        a[i] = x;
        rep(j,0,31){
            int q = (1 << j);
            if (a[i]&q) continue;
            if (!(y&q) || (a[1]&q)) continue;
            a[i] += q;
        }
    }
    sort(a+1,a+n+1);
    cout << "finish " << a[k] << endl;
    return 0;
}