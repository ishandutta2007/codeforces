#include <bits/stdc++.h>
using namespace std;
 
int a[50001];
int b[50001];
 
bool f(int x,int y,int m) {
    if (x<y) {
        swap(x,y);
    }
    while (x!=y) {
        if (x%m!=0) {
            return true;
        }
        x/=m;
    }
    return false;
}
 
int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        int k;
        scanf("%d",&k);
        for(int i=0;i<k;i++) {
            scanf("%d",&b[i]);
        }
        int ind=0;
        long long sum1=0;
        long long sum2=0;
        bool flag=false;
        for(int i=0;i<n;i++) {
            sum1+=a[i];
            while (ind<k&&sum2<sum1) {
                //printf("%d %d\n",i,ind);
                flag|=f(a[i],b[ind],m);
                if (sum2+b[ind]>sum1) {
                    break;
                }
                sum2+=b[ind];
                ind++;
            }
        }
sum2=0;
for(int i=0;i<k;i++) sum2+=b[i];
        if (sum1!=sum2) {
            flag=true;
        }
        printf("%s\n",flag?"No":"Yes");
    }
    return 0;
}