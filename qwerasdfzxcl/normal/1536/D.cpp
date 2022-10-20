#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200200];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    set<int> st;
    bool ans = 1;
    st.insert(a[0]);
    for (int i=1;i<n;i++){
        auto iter = st.find(a[i-1]);
        st.insert(a[i]);
        if (a[i]==a[i-1]) continue;
        if (a[i]>a[i-1]){
            if (*(++iter)!=a[i]){
                ans = 0; break;
            }
        }
        else{
            if (*(--iter)!=a[i]){
                ans = 0; break;
            }
        }
    }
    if (ans) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}