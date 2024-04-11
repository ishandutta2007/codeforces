#include <iostream>
#include <stack>

using namespace std;
int h[200002];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i=1;i<=n;i++){
            scanf("%d", &h[i]);
        }

        bool pos = true;

        int u = h[1], d = h[1];
        for(int i=2;i<=n;i++){
            if(u + k - 1 < h[i]){
                pos = false;
                break;
            }
            if(d > h[i] + 2*(k - 1)){
                pos = false;
                break;
            }

            u = min(u, h[i]) + k - 1;
            d = max(d - (k - 1), h[i]);

        }

        if(!pos) printf("no\n");
        else if(d > h[n]) printf("no\n");
        else printf("yes\n");
    }
}