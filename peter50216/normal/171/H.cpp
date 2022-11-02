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
struct XD{
    int x,y;
    XD(int xx,int yy):x(xx),y(yy){}
    void print(){printf("%d %d\n",x,y);}
};
int pows[30];
inline XD solve(int a,int b){
    if(a==0)return XD(0,0);
    int sz=pows[2*(a-1)];
    XD k=solve(a-1,b%sz);
    swap(k.x,k.y);
    if(b<sz)return k;
    else if(b<2*sz){
        swap(k.x,k.y);
        ///if(a%2){
        //    k.x+=pows[a-1];
        //}else{
            k.y+=pows[a-1];
        //}
    }else if(b<3*sz){
        swap(k.x,k.y);
        k.x+=pows[a-1];
        k.y+=pows[a-1];
    }else{
        //if(a%2){
        //    k.x=pows[a-1]-1-k.x;
        //    k.y=pows[a]-1-k.y;
       // }else{
            k.x=pows[a]-1-k.x;
            k.y=pows[a-1]-1-k.y;
       // }
    }
    return k;
}
int main(){
    int a,b,i;
    pows[0]=1;
    for(i=1;i<30;i++)pows[i]=pows[i-1]*2;
    while(scanf("%d%d",&a,&b)!=EOF){
        solve(a,b).print();
    }
}