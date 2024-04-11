#include<bits/stdc++.h>
using namespace std;
#define author rajat1603
inline int scan(){
    char c = getchar();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar();
    }
    return x;
}
const int N = 200000;
int bit[N+1]={0};
void update(int index,int val){
    while(index<=N){
        bit[index]=max(bit[index],val);
        index+=index&-index;
    }
}
int query(int index){
    int res=0;
    while(index){
        res=max(res,bit[index]);
        index&=index-1;
    }
    return res;
}
int main(){
    int n=scan();
    while(n--){
        int x=scan();
        update(x,query(x-1)+1);
    }
    printf("%d\n",query(N));
}