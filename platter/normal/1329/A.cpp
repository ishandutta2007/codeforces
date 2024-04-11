#include <bits/stdc++.h>
using namespace std;
 
int l[100000];
 
int main(void) {
    int n,m;
    scanf("%d %d\n",&n,&m);
    long long total=0;
    for(int i=0;i<m;i++) {
        scanf("%d ",&l[i]);
        total+=l[i];
    }
    if (total<n) {
        printf("-1");
        return 0;
    }
    bool flag=true;
    for(int i=0;i<m;i++) {
        if (l[i]>n-i) {
            flag=false;
        }
    }
    if (!flag) {
        printf("-1");
        return 0;
    }
    queue<int> s;
    s.push(1);
    long long left=total-l[0];
    for(int i=1;i<m;i++) {
        if (n-i<=left) {
            s.push(i+1);
            left-=l[i];
        }
        else {
            s.push(n-left+1);
            int now=n-left+l[i];
            for(int j=i+1;j<m;j++) {
                s.push(now+1);
                now+=l[j];
            }
            break;
        }
    }
    while (!s.empty()) {
        printf("%d ",s.front());
        s.pop();
    }
}