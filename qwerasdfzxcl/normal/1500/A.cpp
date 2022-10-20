#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200200], b[5050];
unordered_map<int, set<pair<int, int>>> st;

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    if (n>3000) n = 3000;
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            int val = a[i]+a[j];
            auto iter0 = st[val].end(), iter1=st[val].lower_bound(make_pair(i, -1e9)), iter2 = st[val].lower_bound(make_pair(j, -1e9));
            if (iter0!=st[val].begin()){
                --iter0;
                if (iter0->first!= i && iter0->first!=j){
                    printf("YES\n%d %d %d %d", iter0->first+1, iter0->second+1, i+1, j+1);
                    return;
                }
            }
            if (iter1!=st[val].begin()){
                --iter1;
                if (iter1->first!= i && iter1->first!=j){
                    printf("YES\n%d %d %d %d", iter1->first+1, iter1->second+1, i+1, j+1);
                    return;
                }
            }
            if (iter2!=st[val].begin()){
                --iter2;
                if (iter2->first!= i && iter2->first!=j){
                    printf("YES\n%d %d %d %d", iter2->first+1, iter2->second+1, i+1, j+1);
                    return;
                }
            }
            b[j]=val;
        }
        unordered_map<int, int> cnt;
        for (int j=i+1;j<n;j++){
            if (cnt[b[j]]>=2) continue;
            st[b[j]].insert(make_pair(j, i));
            cnt[b[j]]++;
        }
    }
    assert(n<3000);
    printf("NO\n");
}

int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}