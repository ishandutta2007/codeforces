#include <iostream>

using namespace std;
int v[100002];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        int r = 0;
        for(int i=1;i<=n;i++){
            scanf("%d", &v[i]);
            if(v[i] != i) r = i;
        }
        double pos = 1;
        for(int i=1;i<=m;i++){
            int _r; double p;
            scanf("%d %lf", &_r, &p);
            if(r <= _r) pos *= (1-p);
        }
        if(r == 0){
            printf("1.000000\n");
            continue;
        }

        printf("%.6lf\n", (1-pos));
    }
}