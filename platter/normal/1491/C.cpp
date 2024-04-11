#include <bits/stdc++.h>
using namespace std;

int arr[100000];
int n,q;
int cnt=0;
int p[5001];

int find(int a) {
    if (p[a]<0) {
        return a;
    }
    return p[a]=find(p[a]);
}

void merge(int a,int b) {
    a=find(a);
    b=find(b);
    if (a==b) {
        return;
    }
    p[a]+=p[b];
    p[b]=a;
}

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        memset(p,-1,sizeof(p));
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
            if (arr[i]==1) {
                merge(i+1,i);
            }
        }
        long long ret=0;
        while (-p[find(0)]!=n+1) {
            int now=find(0);
            if (arr[now]>n) {
                ret+=arr[now]-n;
                arr[now]=n;
                if (arr[now]==1) {
                    merge(now+1,now);
                    break;
                }
            }
            while (1) {
                if (now+arr[now]>=n) {
                    arr[now]--;
                    if (arr[now]==1) {
                        merge(now+1,now);
                    }
                    break;
                }
                int nt=find(now+arr[now]);
                arr[now]--;
                if (arr[now]==1) {
                    merge(now+1,now);
                }
                if (nt>=n) {
                    break;
                }
                now=nt;
            }
            ret++;
        }
        printf("%lld\n",ret);
    }
}