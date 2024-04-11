#include <cstdio>

using namespace std;

int area[100005],jumps[100005],n,been[100005];
char dir[100005];

int main(){
    scanf("%d",&n);
    scanf("%s",dir);
    for(int i =  0;i<n;i++){
        scanf("%d",&jumps[i]);
        been[i] = 0;
    }
    int cur = 0;
    while(1){
        if(cur < 0 || cur >= n){
            printf("FINITE");
            return 0;
        }
        if(been[cur]){
            printf("INFINITE");
            return 0;
        }
        been[cur] = 1;
        if(dir[cur] == '<'){
            cur-=jumps[cur];
        }
        else{
            cur+=jumps[cur];
        }
    }
}