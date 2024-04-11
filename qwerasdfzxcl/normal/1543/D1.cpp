#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    set<int> st;
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=0;i<n;i++) st.insert(i);
    int cur = 0;
    while(!st.empty()){
        printf("%d\n", *st.begin()^cur);
        fflush(stdout);
        int x;
        scanf("%d", &x);
        if (x==1) return;
        cur ^= *st.begin()^cur;
        st.erase(st.begin());
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