#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100], b[100100], ans[100100];
pair<int, int> c[100100];
vector<pair<int, int>> cha;

void solve(){
    cha.clear();
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    for (int i=0;i<n;i++) scanf("%d", b+i);
    for (int i=0;i<m;i++){
         scanf("%d", &c[i].first);
         c[i].second=i;
    }
    fill(ans, ans+m, -1);
    int la=c[m-1].first;
    for (int i=0;i<n;i++){
        if (a[i]!=b[i]) cha.push_back(make_pair(b[i], i));
    }
    if ((int)cha.size()>m){
        printf("NO\n"); return;
    }
    /*if (!cha.size()){
        bool chk=0;
        int anss=0;
        for (int i=0;i<n;i++) if (b[i]==la){
            chk=1; anss=i;break;
        }
        if (chk){
            printf("YES\n");
            for (int i=0;i<m;i++) printf("%d ", anss);
        }
        else printf("NO\n");
        return;
    }*/
    sort(c, c+m);
    sort(cha.begin(), cha.end());
    int pt1=0, pt2=0;
    while(pt1<(int)cha.size() && pt2<m){
        if (c[pt2].first==cha[pt1].first){
            ans[c[pt2].second]=cha[pt1].second;
            pt1++; pt2++;
        }
        else pt2++;
    }
    if (pt1!=(int)cha.size()){
        printf("NO\n");
        return;
    }
    bool chk=0;
    int anss=0;
    for (int i=0;i<n;i++) if (b[i]==la){
        chk=1; anss=i;break;
    }
    if (!chk){
        printf("NO\n");
        return;
    }
    if (ans[m-1]!=-1) anss=ans[m-1];
    printf("YES\n");
    for (int i=0;i<m;i++){
        if (ans[i]==-1) printf("%d ", anss+1);
        else printf("%d ", ans[i]+1);
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}