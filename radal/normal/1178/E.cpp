#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 1e6+20,mod = 998244353 ,inf = 1e9+10,maxm = (1 << 18)+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k /= 2;
    }
    return z;
}
inline bool pr(int x){
    for (int i = 2; i*i <= x; i++){
        if (x%i == 0) return 0;
    }
    return 1;
}
string g[3]; //ab ac bc
int ind[3][2];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    memset(ind,-1,sizeof ind);
    string s;
    cin >> s;
    int n = s.size();
    rep(i,0,n){
        if (s[i] == 'a'){
            ind[0][1] = i;
            if (ind[0][0] == -1) ind[0][0] = i;
            g[0] += 'a';
            g[1] += 'a';
            continue;
        }
        if (s[i] == 'b'){
            ind[1][1] = i;
            if (ind[1][0] == -1) ind[1][0] = i;
            g[0] += 'b';
            g[2] += 'b';
            continue;
        }
        ind[2][1] = i;
        if (ind[2][0] == -1) ind[2][0] = i;
        g[2] += 'c';
        g[1] += 'c';
    }
    int cnt = 0;
    int m = g[0].size();
    rep(i,1,m){
        if (g[0][i] == 'b' && g[0][i-1] == 'a') cnt+=2;
    }
    if (m && g[0][m-1] == 'b') cnt--;
    else if (m) cnt++;
    if (cnt >= n/2){
        cout << 'a';
        cnt /= 2;
        rep(i,0,cnt){
            cout << "ba";
        }
        return 0;
    }
    cnt = 0;
    rep(i,1,m){
        if (g[0][i] == 'a' && g[0][i-1] == 'b') cnt+=2;
    }
    if (m && g[0][m-1] == 'a') cnt--;
    else if (m) cnt++;
    if (cnt >= n/2){
        cout << 'b';
        cnt /= 2;
        rep(i,0,cnt){
            cout << "ab";
        }
        return 0;
    }
    m = g[1].size();
    cnt = 0;
    rep(i,1,m){
        if (g[1][i] == 'c' && g[1][i-1] == 'a') cnt+=2;
    }
    if (m && g[1][m-1] == 'c') cnt--;
    else if (m) cnt++;
    if (cnt >= n/2){
        cout << 'a';
        cnt /= 2;
        rep(i,0,cnt){
            cout << "ca";
        }
        return 0;
    }
    cnt = 0;
    rep(i,1,m){
        if (g[1][i] == 'a' && g[1][i-1] == 'c'){
            cnt+=2;
        }
    }
    if (m && g[1][m-1] == 'a') cnt--;
    else if (m) cnt++;
    if (cnt >= n/2){
        cout << 'c';
        cnt /= 2;
        rep(i,0,cnt){
            cout << "ac";
        }
        return 0;
    }
    m = g[2].size();
    cnt = 0;
    rep(i,1,m){
        if (g[2][i] == 'c' && g[2][i-1] == 'b') cnt+=2;
    }
    if (m && g[2][m-1] == 'c') cnt--;
    else if (m) cnt++;
    if (cnt >= n/2){
        cout << 'b';
        cnt /= 2;
        rep(i,0,cnt){
            cout << "cb";
        }
        return 0;
    }
    cnt = 0;
    rep(i,1,m){
        if (g[2][i] == 'b' && g[2][i-1] == 'c') cnt+=2;
    }
    if (m && g[2][m-1] == 'b') cnt--;
    else if (m) cnt++;
    if (cnt >= n/2){
        cout << 'c';
        cnt /= 2;
        rep(i,0,cnt){
            cout << "bc";
        }
        return 0;
    }
    string ans = "";
    int p = 0,q = ind[s[0]-'a'][1];
    if (p != q)
        ans += s[0];
    while (p+1 < q-1){
        if (s[p+1] == s[q-1]){
            ans += s[p+1];
            p++;
            q--;
            continue;
        }
        if (p+2 == q-1) break;
        if (s[p+1] == s[q-2]){
            p++;
            q-=2;
            ans += s[p];
            continue;
        }
        if (s[p+2] == s[q-1]){
            p += 2;
            q--;
            ans += s[p];
            continue;
        }
        if (p+2 == q-2) break;
        p += 2;
        q -= 2;
        ans += s[p];
    }
    int sz = ans.size();
    if (q > p+1){
        if (sz*2+1 >= n/2){
            cout << ans << s[p+1];
            reverse(ans.begin(),ans.end());
            cout << ans;
            return 0;
        }
    }
    else{
        if (sz*2 >= n/2){
            cout << ans;
            reverse(ans.begin(),ans.end());
            cout << ans;
            return 0;
        }
    }
    ans = "";
    p = 1,q = ind[s[1]-'a'][1];
    if (p != q)
        ans += s[1];
    while (p+1 < q-1){
        if (s[p+1] == s[q-1]){
            ans += s[p+1];
            p++;
            q--;
            continue;
        }
        if (p+2 == q-1) break;
        if (s[p+1] == s[q-2]){
            p++;
            q-=2;
            ans += s[p];
            continue;
        }
        if (s[p+2] == s[q-1]){
            p += 2;
            q--;
            ans += s[p];
            continue;
        }
        if (p+2 == q-2) break;
        p += 2;
        q -= 2;
        ans += s[p];
    }
    sz = ans.size();
    if (q > p+1){
        if (sz*2+1 >= n/2){
            cout << ans << s[p+1];
            reverse(ans.begin(),ans.end());
            cout << ans;
            return 0;
        }
    }
    else{
        if (sz*2 >= n/2){
            cout << ans;
            reverse(ans.begin(),ans.end());
            cout << ans;
            return 0;
        }
    }
    ans = "";
    p = ind[s[n-1]-'a'][0],q = n-1;
    if (p != q)
        ans += s[n-1];
    while (p+1 < q-1){
        if (s[p+1] == s[q-1]){
            ans += s[p+1];
            p++;
            q--;
            continue;
        }
        if (p+2 == q-1) break;
        if (s[p+1] == s[q-2]){
            p++;
            q-=2;
            ans += s[p];
            continue;
        }
        if (s[p+2] == s[q-1]){
            p += 2;
            q--;
            ans += s[p];
            continue;
        }
        if (p+2 == q-2) break;
        p += 2;
        q -= 2;
        ans += s[p];
    }
    sz = ans.size();
    if (q > p+1){
        if (sz*2+1 >= n/2){
            cout << ans << s[p+1];
            reverse(ans.begin(),ans.end());
            cout << ans;
            return 0;
        }
    }
    else{
        if (sz*2 >= n/2){
            cout << ans;
            reverse(ans.begin(),ans.end());
            cout << ans;
            return 0;
        }
    }
}