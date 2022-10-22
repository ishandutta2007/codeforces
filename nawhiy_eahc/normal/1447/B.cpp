#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        int negmax = -1000, negcount = 0, sum = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int k;
                scanf("%d", &k);
                if(k<=0){
                    sum -= k;
                    negmax = max(negmax, k);
                    negcount++;
                }
                else{
                    sum+=k;
                    negmax = max(negmax, -k);
                }
            }
        }
        if(negcount%2==1) sum += 2*negmax;
        printf("%d\n", sum);
    }
}