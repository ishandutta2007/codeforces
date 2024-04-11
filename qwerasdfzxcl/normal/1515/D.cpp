#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n, l, r;
    scanf("%d %d %d", &n, &l, &r);
    multiset<int> s1, s2;
    for (int i=0;i<l;i++){
        int tmp;
        scanf("%d", &tmp);
        s1.insert(tmp);
    }
    for (int i=0;i<r;i++){
        int tmp;
        scanf("%d", &tmp);
        s2.insert(tmp);
    }
    if (l>r) swap(s1, s2);
    vector<int> del;
    for (auto &x:s1){
        if (s2.find(x)==s2.end()) continue;
        del.push_back(x);
        s2.erase(s2.find(x));
    }
    for (auto &x:del) s1.erase(s1.find(x));
    vector<int> sl, sr;
    for (auto &x:s1) sl.push_back(x);
    for (auto &x:s2) sr.push_back(x);
    sort(sr.begin(), sr.end());
    int ans=sl.size(), cur=sr.size();
    for (int i=1;i<(int)sr.size();){
        if (cur<=(int)sl.size()) break;
        if (sr[i]==sr[i-1]){
            ans++;
            cur -= 2;
            i += 2;
            continue;
        }
        i++;
    }
    int tmpx = (cur-sl.size())/2;
    ans += tmpx*2;
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}