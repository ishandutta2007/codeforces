#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int f[200200], mn[200200], mx[200200];
bool inv[200200];
vector<pair<int, int>> prt;

int main(){
    int n;
    scanf("%d", &n);
    bool chk1=0;
    for (int i=0;i<n;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if (a<=n && b<=n){
            chk1=1; continue;
        }
        if (a>n && b>n){
            chk1=1; continue;
        }
        if (a>n){
            inv[b-1]=1; swap(a, b);
        }
        f[a-1]=b-1;
    }
    if(chk1){
        printf("-1\n");
        return 0;
    }
    mn[0]=f[0], mx[n-1]=-1e9;
    for (int i=1;i<n;i++) mn[i]=min(mn[i-1], f[i]);
    for (int i=n-2;i>=0;i--) mx[i] = max(mx[i+1], f[i+1]);
    prt.push_back(make_pair(0, n));
    for (int i=0;i<n-1;i++){
        if (mn[i]>mx[i]){
            prt.back().second=i+1;
            prt.push_back(make_pair(i+1, n));
        }
    }
    bool chk2=0;
    int ans=0;
    for (auto &p:prt){
        vector<int> tmp1, tmp2;
        tmp1.push_back(f[p.first]);
        int val=0;
        if (inv[p.first]) val++;
        for (int i=p.first+1;i<p.second;i++){
            if (tmp1.back()>f[i]){
                tmp1.push_back(f[i]);
                if (inv[i]) val++;
            }
            else{
                if (!tmp2.empty() && tmp2.back()<=f[i]){
                    chk2=1; break;
                }
                tmp2.push_back(f[i]);
                if (!inv[i]) val++;
            }
        }
        ans += min(val, p.second-p.first-val);
        if (chk2) break;
    }
    if (chk2){
        printf("-1\n");
        return 0;
    }
    printf("%d\n", ans);
    return 0;
}