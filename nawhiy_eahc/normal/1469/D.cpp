#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        int sqtn;
        int sqtsqtn;
        scanf("%d", &n);

        for(int i=1;i<=n;i++){
            if(i*i >= n){
                sqtn = i;
                break;
            }
        }

        for(int i=1;i<=sqtn;i++){
            if(i*i >= sqtn){
                sqtsqtn = i;
                break;
            }
        }

        if(n == 3){
            printf("2\n3 2\n3 2\n");
            continue;
        }
        if(n == 4){
            printf("3\n3 4\n4 2\n4 2\n");
            continue;
        }

        if(sqtsqtn == 2){
            printf("%d\n", n + 3);
            for(int i=3;i<n;i++){
                if(i != sqtn) printf("%d %d\n", i, n);
            }

            printf("%d %d\n", n, sqtn);
            printf("%d %d\n", n, sqtn);

            for(int i=1;i<=5;i++){
                printf("%d %d\n", sqtn, 2);
            }
        }

        else{
            printf("%d\n", n + 4);
            for(int i=3;i<n;i++){
                if(i != sqtn && i != sqtsqtn) printf("%d %d\n", i, n);
            }

            printf("%d %d\n", n, sqtn);
            printf("%d %d\n", n, sqtn);
            printf("%d %d\n", sqtn, sqtsqtn);
            printf("%d %d\n", sqtn, sqtsqtn);

            for(int i=1;i<=5;i++){
                printf("%d %d\n", sqtsqtn, 2);
            }
        }
    }
}