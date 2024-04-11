#include <iostream>
#include <algorithm>

using namespace std;
int v[300002];
int tree[1200002];
int p[300002];

int init(int i, int l, int r){
    if(l==r) return tree[i] = v[l];
    int m = (l+r)/2;
    return tree[i] = min(init(i*2, l, m), init(i*2+1, m+1, r));
}

int query(int i, int l, int r, int s, int e){
    if(l > e || r < s) return 500000;
    if(l >= s && r <= e) return tree[i];
    int m = (l+r)/2;
    return min(query(i*2, l, m, s, e), query(i*2+1, m+1, r, s, e));
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i=1;i<=4*n;i++) tree[i] = 0;
        for(int i=1;i<=n;i++){
            scanf("%d", &v[i]);
            p[i] = 0;
        }
        init(1, 1, n);
        int cnt = n;
        for(int i=1, j=n; i < j;){
            if(query(1, 1, n, i, j) == n-cnt+1) p[cnt--] = 1;
            else break;
            if(v[i] == n-cnt) i++;
            else if(v[j] == n-cnt) j--;
            else break;
        }
        sort(v+1, v+n+1);
        bool pos = true;
        for(int i=1;i<=n;i++){
            if(v[i] != i) pos = false;
        }
        if(pos) p[1] = 1;

        for(int i=1;i<=n;i++){
            printf("%d", p[i]);
        }
        printf("\n");
    }
}