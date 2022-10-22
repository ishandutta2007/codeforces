#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, c0, c1, h, sum = 0;
        scanf("%d%d%d%d", &n, &c0, &c1, &h);
        c0 = min(c0, c1+h);
        c1 = min(c1, c0+h);
        for(int i=1;i<=n;i++){
            int b;
            scanf("%1d", &b);
            if(b) sum+=c1;
            else sum+=c0;
        }
        printf("%d\n", sum);
    }
}