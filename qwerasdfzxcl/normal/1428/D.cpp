#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[100100];

int main(){
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", a+i);
    int cur = n;
    bool chk = 1;
    vector<pair<int, int>> rem, rans, rem2;
    for (int i=n;i;i--){
        if (!a[i]) continue;
        if (a[i]==1){
            assert(cur>0);
            rem.emplace_back(cur, i);
            rans.emplace_back(cur, i);
            cur--;
            continue;
        }
        if (a[i]==2){
            if (rem.empty()){
                chk = 0; break;
            }
            rans.emplace_back(rem.back().first, i);
            rem2.emplace_back(rem.back().first, i);
            rem.pop_back();

        }
        else {
            assert(cur>0);
            if (rem2.empty()){
                if (rem.empty()){
                    chk = 0; break;
                }
                rans.emplace_back(cur, i);
                rans.emplace_back(cur, rem.back().second);
                rem.pop_back();
                rem2.emplace_back(cur, i);
                cur--;
                continue;

            }
                rans.emplace_back(cur, i);
                rans.emplace_back(cur, rem2.back().second);
                rem2.pop_back();
                rem2.emplace_back(cur, i);
                cur--;

        }
    }
    if (!chk){
        printf("-1\n"); return 0;
    }
    printf("%d\n", (int)rans.size());
    for (auto &p:rans) printf("%d %d\n", p.first, p.second);
    return 0;
}