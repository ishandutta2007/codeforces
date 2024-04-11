#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<int> ans;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        ans.clear();
        ll k;
        scanf("%lld", &k);
        if (k%2==1){
            printf("-1\n");
            continue;
        }

        ll tmp=2, ans2=0, ans3=0;
        bool check=0;
        for (int i=1;i<63;i++){
            tmp*=2;
            if (k%tmp){
                k -= tmp/2;
                if (i==1){
                    check=1;
                    ans2++;
                    continue;
                }
                ans2+=(i-1);
                ans3++;
                ans.push_back(i-1);
            }
        }
        printf("%lld\n", ans2+ans3);
        if (check) printf("1 ");
        for (auto &x:ans){
            printf("1 ");
            for (int i=0;i<x-1;i++) printf("0 ");
        }
        for (ll i=0;i<ans3;i++) printf("1 ");
        printf("\n");
    }
    return 0;
}