#include <bits/stdc++.h>

struct flet{
    int f;
    int num;
    flet(){}
    flet(int _f, int _num){
        f=_f;
        num=_num;
    }
    bool operator<(const flet &v) const{
        return f<v.f;
    }
};

using namespace std;
int a[6];
flet b[600001];
int check[100001]={0};

int main()
{
    for (int i=0;i<6;i++) scanf("%d", &a[i]);
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        int tmp;
        scanf("%d", &tmp);
        for (int j=0;j<6;j++) b[6*i+j]=flet(tmp-a[j], i);
    }
    sort(b, b+6*n);
    //for (int i=0;i<6*n;i++) printf("%d %d\n", b[i].f, b[i].num);
    int x=0, y=0, c=1, ans=2000000000;
    check[b[0].num] =1;
    while (true){
        if (c<n){
            if (y==6*n-1) break;
            y += 1;
            if (check[b[y].num]==0) c += 1;
            check[b[y].num] += 1;
        }
        else if (c==n){
            ans=min(ans, b[y].f-b[x].f);
            if (check[b[x].num]==1) c -= 1;
            check[b[x].num] -= 1;
            x += 1;
        }
    }
    printf("%d", ans);
    return 0;
}