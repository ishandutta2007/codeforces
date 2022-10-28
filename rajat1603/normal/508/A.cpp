#include<bits/stdc++.h>
using namespace std;
inline int scan(){
    int x;
    scanf("%d",&x);
    return x;
}
#define pb push_back
#define mp make_pair
bool b[1005][1005]={0};
int main(){
    int n=scan(),m=scan(),k=scan();
    for(int i=1;i<=k;i++){
        int x=scan(),y=scan();
        if(b[x][y]==0){
            b[x][y]=1;
            if(b[x][y]&b[x][y-1]&b[x-1][y]&b[x-1][y-1]){
                printf("%d",i);
                return 0;
            }
            else if(b[x][y]&b[x][y-1]&b[x+1][y]&b[x+1][y-1]){
                printf("%d",i);
                return 0;
            }
            else if(b[x][y]&b[x][y+1]&b[x-1][y]&b[x-1][y+1]){
                printf("%d",i);
                return 0;
            }
            else if(b[x][y]&b[x][y+1]&b[x+1][y]&b[x+1][y+1]){
                printf("%d",i);
                return 0;
            }
        }
    }
    printf("0");
}