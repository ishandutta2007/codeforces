#include<bits/stdc++.h>
#define MAXN 500010
#define inf 1e+15
using namespace std;
char ch;
int n,x,y,ans;
int main(){
    scanf("%d\n",&n);
    ans++;
    for (int i=0;i<n;i++){
        ch=getchar();
        if (ch=='R'){
            if (x==0) x=1;
            else if (x==2){
                x=1;
                y=0;
                ans++;
            }
        }
        else if (ch=='L'){
            if (x==0) x=2;
            else if (x==1){
                x=2;
                y=0;
                ans++;
            }
        }
        else if (ch=='U'){
            if (y==0) y=1;
            else if (y==2){
                y=1;
                x=0;
                ans++;
            }
        }
        else{
            if (y==0) y=2;
            else if (y==1){
                y=2;
                x=0;
                ans++;
            }
        }
    }
    printf("%d\n",ans);
}