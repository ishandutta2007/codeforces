#include <iostream>

using namespace std;

int r[102];
int b[102];
int a[202];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d", &r[i]);
        }
        int m;
        scanf("%d", &m);
        for(int i=0;i<m;i++){
            scanf("%d", &b[i]);
        }

        int maxr = 0, maxb = 0;
        int sumr = 0, sumb = 0;
        for(int i=0;i<n;i++){
            sumr += r[i];
            maxr = max(maxr, sumr);
        }

        for(int i=0;i<m;i++){
            sumb += b[i];
            maxb = max(maxb, sumb);
        }

        printf("%d\n", maxb + maxr);
    }
}