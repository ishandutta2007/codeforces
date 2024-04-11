#include<bits/stdc++.h>
using namespace std;
int n,x,d;
char s[10];
int main(){
    scanf("%d",&n);
    while (n--){
        scanf("%d%s",&d,s);
        while (d){
            if (x==0){
                if (s[0]!='S'){
                    printf("NO\n");
                    return 0;
                }
                x=x+min(d,20000);
                d-=min(d,20000);
            }
            else if (x==20000){
                if (s[0]!='N'){
                    printf("NO\n");
                    return 0;
                }
                x=x-min(d,20000);
                d-=min(d,20000);
            }
            else if (s[0]=='S'){
                int tmp=min(d,20000-x);
                x=x+tmp;
                d-=tmp;
            }
            else if (s[0]=='N'){
                int tmp=min(d,x);
                x=x-tmp;
                d-=tmp;
            }
            else d=0;
        }
    }
    if (x) printf("NO\n");
    else printf("YES\n");
    return 0;
}