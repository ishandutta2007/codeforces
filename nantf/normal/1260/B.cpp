#include<bits/stdc++.h>
using namespace std;
int t,a,b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        if(a>b) swap(a,b);
        if(2*a<b){puts("NO");continue;}
        int x=b-a;
        a-=x;b-=2*x;
        puts(a%3?"NO":"YES");
    }
}