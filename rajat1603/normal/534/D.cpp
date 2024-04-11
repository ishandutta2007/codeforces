#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
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
const int N = 200001;
int n,ans[N];
queue<int> v[N];
int main(){
    n=scan();
    for(int i=1;i<=n;++i){
        v[scan()].push(i);
    }
    int cur=0;
    for(int i=1;i<=n;++i){
        while(1){
            if(cur<0){
                printf("Impossible");
                return 0;
            }
            if(!v[cur].empty()){
                ans[i]=v[cur].front();
                v[cur++].pop();
                break;
            }
            else{
                cur-=3;
            }
        }
    }
    printf("Possible\n");
    for(int i=1;i<=n;++i){
        printf("%d ",ans[i]);
    }
}