#include <iostream>

using namespace std;
int v[502];
bool check(int x, int y){
    bool b = true;
    for(int i=x;i<y;i++){
        if(v[i]>v[i+1]) b = false;
    }
    return b;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        int x;
        int p = 1;
        scanf("%d%d", &n, &x);
        for(int i=1;i<=n;i++){
            scanf("%d", &v[i]);
        }
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(check(1, n)) break;
            if(x < v[i]){
                swap(x, v[i]);
                cnt++;
            }
        }

        if(check(1, n)) printf("%d\n", cnt);
        else printf("-1\n", cnt);
    }
}