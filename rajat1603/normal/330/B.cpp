#include<bits/stdc++.h>
#define getchar_unlocked getchar
using namespace std;
inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}
int main(){
    int n=scan(),m=scan();
    bool b[1001]={0};
    while(m--){
        b[scan()]=1;
        b[scan()]=1;
    }
    cout<<n-1<<endl;
    for(int i=1;i<=n;i++){
        if(!b[i]){
            for(int j=1;j<=n;j++){
                if(j!=i){
                    printf("%d %d\n",i,j);
                }
            }
            return 0;
        }
    }
}