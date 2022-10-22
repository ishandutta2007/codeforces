#include <iostream>
#include <vector>

using namespace std;
int cnt[100002];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        long long n;
        scanf("%lld", &n);
        for(int i=1;i<=100000;i++){
            cnt[i] = 0;
        }
        long long m = n;
        for(long long i=2;i*i<=m;i++){
            if(n%i==0){
                while(n%i==0){
                    cnt[i]++;
                    n/=i;
                }
            }
            if(n==1) break;
        }
        cnt[1] = 1;
        int l=1;
        for(int i=2;i<=100000;i++){
            if(cnt[l]<cnt[i]) l = i;
        }
        printf("%d\n", cnt[l]);
        for(int i=1;i<=cnt[l]-1;i++){
            printf("%d ", l);
            m/=l;
        }
        printf("%lld\n", m);
    }
}