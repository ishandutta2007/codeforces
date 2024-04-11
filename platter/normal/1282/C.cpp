#include <cstdio>
#include <algorithm>
using namespace std;
 
typedef pair<long long,bool> P;
P arr[200055];
 
int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int tc=0;tc<c;tc++) {
        int n;
        long long t,a,b;
        scanf("%d %lld %lld %lld\n",&n,&t,&a,&b);
        long long easy=0;
        long long dif=0;
        for(int i=0;i<n;i++) {
            int x;
            scanf("%d ",&x);
            arr[i].second=x;
            if (x==0) {
                easy+=1;
            }
            else {
                dif+=1;
            }
        }
        scanf("\n");
        for(int i=0;i<n;i++) {
            long long x;
            scanf("%lld ",&x);
            arr[i].first=x;
        }
        scanf("\n");
        if (easy*a+dif*b<=t) {
            printf("%d\n",n);
            continue;
        }
        int ret=0;
        sort(arr,arr+n);
        long long copy=arr[0].first-1;
        if (copy>=0) {
            int solved=0;
                if ((copy/a)>easy) {
                    solved+=easy;
                    copy-=a*easy;
                    solved+=min(copy/b,dif);
                }
                else {
                    solved+=copy/a;
                }
            ret=solved;
        }
        long long prev=arr[0].first;
        long long total=0;
        if (!arr[0].second) {
            easy-=1;
            total+=a;
        }
        else {
            dif-=1;
            total+=b;
        }
        for(int i=1;i<n;i++) {
            if (arr[i].first!=prev) {
                long long s=arr[i].first-1;
                if (total<=s) {
                    long long copy=s-total;
                    int solved=i;
                    if ((copy/a)>easy) {
                        solved+=easy;
                        copy-=a*easy;
                        solved+=min(copy/b,dif);
                    }
                    else {
                        solved+=copy/a;
                    }
                    ret=max(solved,ret);
                }
            }
            prev=arr[i].first;
            if (!arr[i].second) {
                easy-=1;
                total+=a;
            }
            else {
                dif-=1;
                total+=b;
            }
        }
        printf("%d\n",ret);
        for(int i=0;i<n;i++) {
            arr[i].first=0;
            arr[i].second=false;
        }
    }
    return 0;
}