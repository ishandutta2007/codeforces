#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int maxn=100002;
bool a[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x;
        scanf("%d",&x);
        a[x]=true;
    }
    for(int i=1;i<=n;i++)if(!a[i]){printf("%d\n",i);return 0;}
}