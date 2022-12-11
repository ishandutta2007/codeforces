#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 10;
const int M = (int)1e6 + 10;
int a[N];
vector<int> d[M];
vector<int> f[M];
int po[M];
int lf[N];
int rf[N];
int li[N];
int ri[N];
int la;
int ra;
int lb;
int rb;
int cut;

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
        f[a[i]].push_back(i);
        po[a[i]] = 0;
    }
    a[0] = a[n + 1] = M - 1;
    vector<int> st;
    st.push_back(0);
    for(int i = 1; i <= n; i ++ ){
        while(a[i] > a[st.back()]) st.pop_back();
        lf[i] = st.back();
        st.push_back(i);
    }
    st.clear();
    st.push_back(n + 1);
    for(int i = n; i >= 1; i -- ){
        while(a[i] >= a[st.back()]) st.pop_back();
        rf[i] = st.back();
        st.push_back(i);
    }
    st.clear();
    a[0] = a[n + 1] = 0;
    st.push_back(0);
    for(int i = 1; i <= n; i ++ ){
        while(a[i] <= a[st.back()]) st.pop_back();
        li[i]=st.back();
        st.push_back(i);
    }
    st.clear();
    st.push_back(n + 1);
    for(int i = n; i >= 1; i -- ){
        while(a[i] <= a[st.back()]) st.pop_back();
        ri[i]=st.back();
        st.push_back(i);
    }
    int i1, j1;
    ll res = 0;
    for(int i = 1; i <= n; i ++ ){
        for(auto di : d[a[i]]){
            while(po[di] < f[di].size() && f[di][po[di]] < i){
                po[di] ++ ;
            }
            i1 = j1 = -1;
            if(po[di] < f[di].size() && f[di][po[di]] >= i){
                j1 = f[di][po[di]];
            }
            if(po[di] - 1 >= 0 && f[di][po[di] - 1] < i){
                i1 = f[di][po[di] - 1];
            }
            if(i1 != -1){
                la = lf[i] + 1;
                ra = rf[i] - 1;
                ra = min(ra, ri[i1] - 1);
                la = max(la, li[i1] + 1);
                if(la <= i1 && i <= ra)
                    res += (i1 - la + 1) * 1ll * (ra - i + 1);
            }
            if(j1 != -1){
                la = lf[i] + 1;
                ra = rf[i] - 1;
                la = max(la, li[j1] + 1);
                ra = min(ra, ri[j1] - 1);
                if(la <= i && j1 <= ra){
                    res += (i - la + 1) * 1ll * (ra - j1 + 1);
                }
            }
            if(i1 != -1 && j1 != -1){
                la = lf[i] + 1;
                rb = rf[i] - 1;

                la = max(la, li[i1] + 1);
                rb = min(rb, ri[i1] - 1);
                la = max(la, li[j1] + 1);
                rb = min(rb, ri[j1] - 1);
                if(la <= i1 && j1 <= rb)
                    res -= (i1 - la + 1) * 1ll * (rb - j1 + 1);
            }
        }
    }
    cout << res << "\n";
    for(int i = 1; i <= n; i ++ ){
        f[a[i]].clear();
        po[a[i]] = 0;
    }
}


int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int i = 1; i < M ; i ++ ){
        for(int j = i ; j < M; j += i){
            d[j].push_back(i);
        }
    }
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}