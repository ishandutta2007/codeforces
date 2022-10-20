#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
map<int, int> mp[200200];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int cnt1 = 0, cnt2 = 0;
    for (int i=0;i<m;i++){
        char op;
        scanf(" %c", &op);
        if (op=='+'){
            int x, y;
            char z;
            scanf("%d %d %c", &x, &y, &z);
            if (mp[y].find(x)!=mp[y].end()){
                cnt1++;
                if ('a'+mp[y][x]==z) cnt2++;
            }
            mp[x][y] = z-'a';
        }
        if (op=='-'){
            int x, y;
            scanf("%d %d", &x, &y);
            if (mp[y].find(x)!=mp[y].end()){
                cnt1--;
                if (mp[x][y]==mp[y][x]) cnt2--;
            }
            mp[x].erase(mp[x].find(y));
        }
        if (op=='?'){
            int x;
            scanf("%d", &x);
            if (x%2==1 && cnt1>0) printf("YES\n");
            else if (x%2==0 && cnt2>0) printf("YES\n");
            else printf("NO\n");
        }
        //printf("%d %d\n", cnt1, cnt2);
    }
    return 0;
}