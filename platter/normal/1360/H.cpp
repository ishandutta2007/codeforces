#include <bits/stdc++.h>
using namespace std;

bool under10[1024];
bool mid[310];
const int zero=152;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n,m;
        scanf("%d %d\n",&n,&m);
        if (m<=10) {
            for(int i=0;i<(1<<m);i++) {
                under10[i]=true;
            }
            for(int i=0;i<n;i++) {
                int val=0;
                for(int j=0;j<m;j++) {
                    int x;
                    scanf("%1d",&x);
                    val+=(x<<(m-1-j));
                }
                under10[val]=false;
                scanf("\n");
            }
            int nums=(1<<m)-n;
            int cnt=0;
            int ind=(nums-1)/2;
            for(int i=0;i<(1<<m);i++) {
                if (under10[i]) {
                    if (cnt==ind) {
                        int ret[10];
                        for(int j=0;j<m;j++) {
                            ret[j]=i%2;
                            i/=2;
                        }
                        for(int j=m-1;j>=0;j--) {
                            printf("%d",ret[j]);
                        }
                        printf("\n");
                        break;
                    }
                    cnt++;
                }
            }
            continue;
        }
        for(int i=0;i<310;i++) {
            mid[i]=true;
        }
        long long middle=(1LL<<(m-1));
        long long down=middle-150;
        for(int i=0;i<n;i++) {
            long long val=0;
            for(int j=0;j<m;j++) {
                long long x;
                scanf("%1lld",&x);
                val+=(x<<(m-1-j));
            }
            scanf("\n");
            if (val<middle-150) {
                down--;
            }
            else if (val<=middle+150) {
                mid[val-middle+zero]=false;
            }
        }
        long long ind=((1LL<<m)-n-1)/2;
        for(int i=2;i<310;i++) {
            if (mid[i]) {
                if (down==ind) {
                    int ret[60];
                    long long x=middle+i-zero;
                    for(int j=0;j<m;j++) {
                        ret[j]=x%2;
                        x/=2;
                    }
                    for(int j=m-1;j>=0;j--) {
                        printf("%d",ret[j]);
                    }
                    printf("\n");
                    break;
                }
                down++;
            }
        }
    }
}