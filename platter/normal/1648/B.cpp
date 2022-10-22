#include <bits/stdc++.h>
using namespace std;

bool ex[1000001];
int pr[1000001];
int nt[1000001];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,c;
        scanf("%d %d",&n,&c);
        for(int i=0;i<n;i++) {
            int x;
            scanf("%d",&x);
            ex[x]=true;
        }
        int prev=0;
        for(int i=1;i<=c;i++) {
            if (ex[i]) {
                prev=i;
            }
            pr[i]=prev;
        }
        prev=1e9;
        for(int i=c;i>0;i--) {
            if (ex[i]) {
                prev=i;
            }
            nt[i]=prev;
        }
        bool flag=true;
        for(int i=1;i<=c;i++) {
            if (ex[i]) {
                for(int j=i;j<=c;j+=i) {
                    if (nt[j]<j+i&&!ex[j/i]) {
                        flag=false;
                    }
                }
            }
        }
        printf("%s\n",flag?"Yes":"No");
        for(int i=1;i<=c;i++) {
            ex[i]=false;
        }
    }
}