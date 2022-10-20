#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[1000];
queue<int> q;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        while(!q.empty()) q.pop();
        int n, x;
        scanf("%d %d", &n, &x);
        for (int i=0;i<n;i++) scanf("%d", &a[i]);
        bool test=1;
        for (int i=1;i<n;i++){
            if (a[i-1]>a[i]) test=0;
        }
        if(test){
            printf("0\n");
            continue;
        }
        int t;
        for (int i=n-1;i>0;i--){
            if (a[i-1]>a[i]) {
                t=i;
                break;
            }
        }
        int tmp=x;
        q.push(x);
        for (int i=0;i<t;i++) {
            if (a[i]>tmp){
                q.push(a[i]);
                tmp=a[i];
                a[i]=-1;
            }
        }
        int ans=(int)q.size()-1;
        for (int i=0;i<t;i++){
            if (a[i]==-1){
                //printf("%d\n", q.front());
                a[i]=q.front();
                q.pop();
            }
        }
        /*for (int i=0;i<n;i++) printf("%d ", a[i]);
        printf("\n");*/
        test=1;
        for (int i=1;i<n;i++){
            if (a[i-1]>a[i]) test=0;
        }
        if (test) printf("%d\n", ans);
        else printf("-1\n");
    }
    return 0;
}