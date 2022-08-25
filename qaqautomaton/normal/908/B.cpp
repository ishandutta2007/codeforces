#include<bits/stdc++.h>
using namespace std;
char s[66][66],go[233];
const int gx[4]={0,0,1,-1};
const int gy[4]={1,-1,0,0};
int pl[4]={0,1,2,3};
int n,m,fx,fy,tx,ty;
int ok(){
    int x=fx,y=fy;
    for(char *a=go;*a;++a){
        x+=gx[pl[*a-'0']];
        y+=gy[pl[*a-'0']];
        if(x==tx&&y==ty)return 1;
        if(x<1||x>n||y<1||y>m||s[x][y]=='#')return 0;
    }
    return 0;
}
int main(){

    scanf("%d%d\n",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%s",s[i]+1);
        for(int j=1;j<=m;++j)if(s[i][j]=='S'){fx=i,fy=j;}
        else if(s[i][j]=='E'){tx=i;ty=j;}
    }
    scanf("%s",go);
    int cnt=0;
    do{
        if(ok())++cnt;
    }while(next_permutation(pl,pl+4));
    printf("%d\n",cnt);
    return 0;
}