#include <bits/stdc++.h>
#define maxn 2020
#define pb push_back
#define debug
typedef long long ll;
using namespace std;

int M[maxn][maxn];

int mid(int a,int b,int c){
    return a+b+c-max(max(a,b),c)-min(min(a,b),c);
}

int main(){
    int n;
    scanf("%d",&n);
    int qx,qy,kx,ky,tx,ty;
    scanf("%d%d%d%d%d%d",&qx,&qy,&kx,&ky,&tx,&ty);
    if(mid(qx,kx,tx) == qx || mid(qy,ky,ty) == qy)
        printf("NO");
    else
        printf("YES\n");
}