#include <cstdio>

using namespace std;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int k,ind  = 0;
char s[N],cc = 'a';

int main(){
    scanf("%d",&k);
    if(!k){
        printf("a\n");
        return 0;
    }
    while(k){
        int c = 1;
        int sum = 0;
        while(c + sum <= k){
            sum += c++;
        }
        while(c){
            s[ind] = cc;
            c--;ind++;
        }
        cc++;
        k -= sum;
    }
    for(int i = 0;i<ind;i++){
        printf("%c",s[i]);
    }
    printf("\n");
}