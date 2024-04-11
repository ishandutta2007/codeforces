#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int k;

int _xor(int x, int y){
    //printf("%d %d: ", x, y);
    int pw = 1;
    vector<int> dig1, dig2;
    for (;pw<1001000;pw*=k){
        dig1.push_back(x%k);
        dig2.push_back(y%k);
        x /= k, y /= k;
    }
    int ret = 0;
    pw = 1;
    for (int i=0;i<(int)dig1.size();i++){
        ret += ((k+dig2[i]-dig1[i])%k)*pw;
        pw *= k;
    }
    //printf("%d\n", ret);
    return ret;
}

int _xor2(int x, int y){
    //printf("%d %d: ", x, y);
    int pw = 1;
    vector<int> dig1, dig2;
    for (;pw<1001000;pw*=k){
        dig1.push_back(x%k);
        dig2.push_back(y%k);
        x /= k, y /= k;
    }
    int ret = 0;
    pw = 1;
    for (int i=0;i<(int)dig1.size();i++){
        ret += ((dig2[i]+dig1[i])%k)*pw;
        pw *= k;
    }
    //printf("%d\n", ret);
    return ret;
}

void solve(){
    set<int> st;
    int n;
    scanf("%d %d", &n, &k);
    for (int i=0;i<n;i++) st.insert(i);
    int cur = 0, cnt = 0;
    while(!st.empty()){
        int ans = 0;
        if (cnt&1) ans = _xor(*st.begin(), cur);
        else ans = _xor2(*st.begin(), cur);
        printf("%d\n", ans);
        fflush(stdout);
        int x;
        scanf("%d", &x);
        if (x==1) return;
        cur = _xor(cur, ans);
        st.erase(st.begin());
        cnt++;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}