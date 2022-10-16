#include <bits/stdc++.h>
using namespace std;
struct Low{
    int num, index;
    bool operator < (const Low& rhs) const{
        return num>rhs.num;
    }
}b[200005];
int a[200005], m, c[200005];
int main(){
    scanf("%d", &m);
    for(int i=0; i<m; i++) scanf("%d", &a[i]);
    for(int i=0; i<m; i++){
        scanf("%d", &b[i].num);
        b[i].index=i;
    }
    sort(b, b+m);
    sort(a, a+m);
    for(int i=0; i<m; i++)
        c[b[i].index]=a[i];
    printf("%d", c[0]);
    for(int i=1; i<m; i++)
        printf(" %d", c[i]);
    printf("\n");
    return 0;
}