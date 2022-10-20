#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int matrix[102][102];
int ansx[200002];
int ansy[200002];
int ans=0;
int pt=0;

void ap(int t1, int t2, int sx, int sy){
    //printf("%d %d %d %d\n", t1, t2, sx, sy);
    for (int i=0;i<3;i++){
        ansx[pt]=sx+(t1%2)+1;
        ansy[pt]=sy+(t2%2)+1;
        pt ++;
        if (i==0) t1 ++;
        if (i==1) {
            //printf("YES %d %d\n", t1, t2);
            t1++;
            t2++;
            //printf("YES %d %d\n", t1, t2);
        }
    }
}

void cal(int sx, int sy){
    //printf("%d %d\n", sx, sy);
    int c=0;
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++) {
            if (matrix[sx+i][sy+j]==1) c++;
        }
    }
    //printf("%d\n", c);
    if (c==4){
        ans += 4;
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++) ap(i, j, sx, sy);
        }
    }
    else if (c==3){
        ans ++;
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                if (matrix[sx+i][sy+j]==0) ap((i+1)%2, (j+1)%2, sx, sy);
            }
        }
    }
    else if (c==2){
        ans += 2;
        if (matrix[sx][sy]==matrix[sx+1][sy] || matrix[sx][sy]==matrix[sx][sy+1]){
            for (int i=0;i<2;i++){
                for (int j=0;j<2;j++){
                    if (matrix[sx+i][sy+j]==0) ap(i, j, sx, sy);
                }
            }
        }
        else{
            for (int i=0;i<2;i++){
                for (int j=0;j<2;j++){
                    if (matrix[sx+i][sy+j]==1) ap(i, j, sx, sy);
                }
            }
        }
    }
    else if (c==1){
        ans += 3;
        int tmp1, tmp2;
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                if (matrix[sx+i][sy+j]==1) tmp1=i, tmp2=j;
            }
        }
        ap(tmp1, tmp2, sx, sy);
        ap((tmp1+1)%2, tmp2, sx, sy);
        ap(tmp1, (tmp2+1)%2, sx, sy);
    }
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++) matrix[sx+i][sy+j]=0;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        char tmp[102];
        for (int i=0;i<n;i++) {
            scanf("%s", tmp);
            for (int j=0;j<m;j++){
                if (tmp[j]=='0') matrix[i][j]=0;
                else matrix[i][j]=1;
            }
        }
        int n0=n-2-(n%2), m0=m-2-(m%2);
        for (int i=0;i<=n0;i+=2){
            for (int j=0;j<=m0;j+=2) cal(i, j);
        }
        if (n%2==1){
            for (int j=0;j<=m0;j+=2) cal(n0+1, j);
        }
        if (m%2==1){
            for (int i=0;i<=n0;i+=2) cal(i, m0+1);
        }
        if (n%2==1 && m%2==1) cal(n0+1, m0+1);
        printf("%d\n", ans);
        for (int i=0;i<ans;i++){
            printf("%d %d %d %d %d %d\n", ansx[3*i], ansy[3*i], ansx[3*i+1], ansy[3*i+1], ansx[3*i+2], ansy[3*i+2]);
        }
        ans =0;
        pt=0;
    }
    return 0;
}