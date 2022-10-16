#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    if(!a&&!b){
        printf("NO\n");
        return 0;
    }
    if(a>b) swap(a, b);
    if(b-a>1) printf("NO\n");
    else printf("YES\n");
    return 0;
}