#include<stdio.h>
#include<algorithm>
using namespace std;
#define scanint(n)   scanf("%d",&n)
int main(){
    int n,m,a[101],b[101],ans=0,x=0,y=0;
    scanint(n);
    for(int i=0;i<n;i++){
        scanint(a[i]);
    }
    scanint(m);
    for(int i=0;i<m;i++){
        scanint(b[i]);
    }
    sort(a,a+n);
    sort(b,b+m);
    while(x<n&&y<m){
        if(a[x]-b[y]==1||b[y]-a[x]==1||a[x]==b[y]){
            ans++;
            x++;
            y++;
            continue;
        }
        else if(a[x]<b[y]){
            x++;
            continue;
        }
        else if(b[y]<a[x]){
            y++;
            continue;
        }
    }
    printf("%d",ans);
}