#include <bits/stdc++.h>
#define maxn 200200
using namespace std;

int xi[maxn];
int xf[maxn];
int yi[maxn];
int yf[maxn];

int xii[maxn];
int xff[maxn];
int yii[maxn];
int yff[maxn];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d%d",xi+i,yi+i,xf+i,yf+i);

    xii[0] = xi[0];
    xff[0] = xf[0];
    yii[0] = yi[0];
    yff[0] = yf[0];
    
    for(int i=1;i<n;i++){
        xii[i] = max(xii[i-1],xi[i]);
        xff[i] = min(xff[i-1],xf[i]);
        yii[i] = max(yii[i-1],yi[i]);
        yff[i] = min(yff[i-1],yf[i]);
    }
    
    int Xi = -2e9, Xf = 2e9, Yi = -2e9, Yf = 2e9;
    
    if(xii[n-2] <= xff[n-2] && yii[n-2] <= yff[n-2]){
        printf("%d %d\n",xii[n-2],yii[n-2]);
        return 0;
    }
    
    for(int i=n-1;i>=0;i--){
        Xi = max(Xi,xi[i]);
        Xf = min(Xf,xf[i]);
        Yi = max(Yi,yi[i]);
        Yf = min(Yf,yf[i]);
        if(i == 1){
            printf("%d %d\n",Xi,Yi);
            return 0;
        }
        if(max(Xi,xii[i-2]) <= min(Xf,xff[i-2]) && max(Yi,yii[i-2]) <= min(Yf,yff[i-2])){
            printf("%d %d\n",max(Xi,xii[i-2]),max(Yi,yii[i-2]));
            return 0;
        }
    }
}