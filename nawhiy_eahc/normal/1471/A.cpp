#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, x;
        scanf("%d %d", &n, &x);
        long long sum = 0, sum_ = 0;
        for(int i=1;i<=n;i++){
            int k;
            scanf("%d", &k);

            sum += k;
            if(k%x == 0) sum_ += k/x;
            else sum_ += (k/x) + 1;
        }

        if(sum%x == 0) sum /= x;
        else sum = sum/x + 1;

        printf("%lld %lld\n", sum, sum_);
    }
}