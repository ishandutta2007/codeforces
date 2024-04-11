#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int h[200200];
int hm[200200];
pair<int, int> ans[200200];

pair<int, int> combine(pair<int, int> a1, pair<int, int> a2){
    if (a1.second<a2.first || a2.second<a1.first) return make_pair(1e9, 0);
    return make_pair(max(a1.first, a2.first), min(a1.second, a2.second));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=0;i<n;i++){
            scanf("%d", h+i);
            hm[i]=h[i]+m-1;
            if (i==0 || i==n-1) hm[i]=h[i];
        }
        ans[0]=make_pair(h[0], h[0]);
        bool test=1;
        for (int i=1;i<n;i++){
            pair<int, int> a1=make_pair(ans[i-1].first-m+1, ans[i-1].second+m-1);
            pair<int, int> a2=make_pair(h[i], hm[i]);
            ans[i]=combine(a1, a2);
            if (ans[i].first==1e9) {
                test=0;
                break;
            }
        }
        if (test) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}