#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=1e6+30,mod = 1e9+7,inf=1e12;
const long double eps = 0.0001;
int cnt[35],cnt2[35],baz[35];
int main(){
    int T;
    cin >> T;
    while (T--){
        memset(cnt,0,sizeof cnt);
        memset(cnt2,0,sizeof cnt2);
        int n,k;
        string a,b;
        cin >> n >> k;
        cin >> a >> b;
        rep(i,0,n){
            cnt[int(a[i])-int('a')]++;
            cnt2[int(b[i])-int('a')]++;
        }
        rep(i,1,n){
            int len = 1;
            bool f = 0;
            while (i < n && a[i] == a[i-1]){
                f = 1;
                i++;
                len++;
            }
            if (f) i--;
            //baz[int(a[i])-int('a')] += len/k;
        }
        bool f = 0;
        rep(i,0,30) 
            if (abs(cnt[i]-cnt2[i]) % k){
                f = 1;
                break;
            }
        if (f){
            cout << "NO" << endl;
            continue;
        }
        f = 0;
        rep(i,0,30){
            if (cnt[i] < cnt2[i]){
                f = 1; 
                break;
            }
            cnt[i] -= cnt2[i];
            cnt[i+1] += cnt[i]/k*k;
        }
        if (f){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;

    }
    return 0;
}