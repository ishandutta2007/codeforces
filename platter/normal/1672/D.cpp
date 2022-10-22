#include <bits/stdc++.h>
using namespace std;

int a[200005];
int b[200005];
int val[200005];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++) {
            scanf("%d",&b[i]);
        }
        for(int i=1;i<=n;i++) {
            val[i]=0;
        }
        int ind=n-1;
bool flag=true;
        for(int i=n-1;i>=0;i--) {
            val[a[i]]--;
            while (ind>=0&&b[ind]==a[i]) {
                val[a[i]]++;
                ind--;
            }
            if (val[a[i]]<0) {
                flag=false;
                break;
            }
        }
        printf("%s\n",flag?"Yes":"No");
    }
}