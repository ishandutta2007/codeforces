#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
pair<int, int> val[101][101];

int chk(int x){
    if (x==3 || x==4 || x==6 || x==7 || x==9) return -1;
    if (x==0) return 0;
    if (x==1) return 1;
    if (x==2) return 5;
    if (x==5) return 2;
    if (x==8) return 8;
    return -1;
}

void solve(){
    int h, m;
    scanf("%d %d", &h, &m);
    char tmp[10];
    scanf("%s", tmp);
    int x, y;
    x = (tmp[1]-'0')+(tmp[0]-'0')*10;
    y = (tmp[4]-'0')+(tmp[3]-'0')*10;
    pair<int, int> ans=make_pair(0, 0);
    if (x==0 && y==0){
        printf("00:00\n");
        return;
    }
    int d=h*m-(x*m+y);
    for (int i=0;i<h;i++){
        for (int j=0;j<m;j++){
            if (!i && !j) continue;
            if (val[i][j].first==-1) continue;
            if (val[i][j].first>=h || val[i][j].second >= m) continue;
            int tmp;
            if (x*m+y>i*m+j) tmp=(i*m+j+h*m)-x*m+y;
            else tmp = (i*m+j)-(x*m+y);
            if (tmp<d){
                ans=make_pair(i, j);
                d=tmp;
            }
        }
    }
    if (ans.first<10) printf("0");
    printf("%d:", ans.first);
    if (ans.second<10) printf("0");
    printf("%d\n", ans.second);
}

int main(){
    for (int i=0;i<100;i++){
        for (int j=0;j<100;j++){
            int d1=i/10, d2=i%10, d3=j/10, d4=j%10;
            if (chk(d1)==-1 || chk(d2)==-1 || chk(d3)==-1 || chk(d4)==-1){
                val[i][j]=make_pair(-1, -1);
                continue;
            }
            int v1=chk(d4)*10+chk(d3), v2=chk(d2)*10+chk(d1);
            val[i][j]=make_pair(v1, v2);
        }
    }
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}