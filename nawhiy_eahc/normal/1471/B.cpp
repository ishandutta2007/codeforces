#include <iostream>

using namespace std;
long long a[100002];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, x;
        scanf("%d %d", &n, &x);
        for(int i=1;i<=n;i++) scanf("%lld", &a[i]);

        long long s = 1000, sid = -1;
        for(int i=1;i<=n;i++){
            int d = 0;
            long long aa = a[i];
            while(aa%x == 0){
                aa /= x;
                d++;
            }

            if(s > d){
                s = d;
                sid = i;
            }
        }

        long long ans = 0;
        for(int i=1;i<sid;i++){
            ans += (s+2) * a[i];
        }
        for(int i=sid;i<=n;i++){
            ans += (s+1) * a[i];
        }

        printf("%lld\n", ans);
    }
}