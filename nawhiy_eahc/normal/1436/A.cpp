#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        int sum = 0;
        for(int i=1;i<=n;i++){
            int k;
            scanf("%d", &k);
            sum += k;
        }

        if(m == sum) printf("YES\n");
        else printf("NO\n");
    }
}