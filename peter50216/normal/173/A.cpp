#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int pc[1010000][2];
char a[1010],b[1010];
int ww(char a,char b){
    if(a=='R'){
        return b=='S'?1:b=='P'?-1:0;
    }else if(a=='S'){
        return b=='P'?1:b=='R'?-1:0;
    }else{
        return b=='R'?1:b=='S'?-1:0;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s%s",a,b);
    int al=strlen(a),bl=strlen(b);
    int i=0,j=0,k;
    pc[0][0]=pc[0][1]=0;
    for(k=1;k<=al*bl;k++){
        int r=ww(a[i],b[j]);
        pc[k][0]=pc[k-1][0];pc[k][1]=pc[k-1][1];
        if(r==1){
            pc[k][1]++;
        }else if(r==-1){
            pc[k][0]++;
        }
        i++;
        if(i==al)i=0;
        j++;
        if(j==bl)j=0;
    }
    int ab=al*bl;
    printf("%d %d\n",pc[ab][0]*(n/ab)+pc[n%ab][0],pc[ab][1]*(n/ab)+pc[n%ab][1]);
}