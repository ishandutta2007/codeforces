#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n,k;
        scanf("%d %d\n",&n,&k);
        set<int> s;
        for(int i=0;i<n;i++) {
            int x;
            scanf("%d",&x);
            s.insert(x);
        }
        if (s.size()>k) {
            printf("-1\n");
            continue;
        }
        int use=k-s.size();
        for(int i=1;i<=n;i++) {
            if (use>0) {
                if (s.find(i)==s.end()) {
                    s.insert(i);
                    use--;
                }
            }
        }
        vector<int> v;
        for(auto curr:s) {
            v.push_back(curr);
        }
        printf("%d\n",n*k);
        for(int i=0;i<n;i++) {
            for(int j=0;j<k;j++) {
                printf("%d ",v[j]);
            }
        }
        printf("\n");
    }
}