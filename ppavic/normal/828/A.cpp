#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f; // Ako mijena pazi na memset
const int MOD = 1e9 + 7;

int a,b,c,n,x,sol = 0;

int main(){
    scanf("%d%d%d",&n,&a,&b);
    for(int i = 0;i<n;i++){
        scanf("%d",&x);
        if(x > 1){
            if(b) b--;
            else sol+=2;
        }
        else{
            if(a) a--;
            else if(b) {b--;c++;}
            else if(c) {c--;}
            else sol++;
        }
    }
    printf("%d\n",sol);
}