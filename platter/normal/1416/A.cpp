#include <bits/stdc++.h>
using namespace std;

vector<int> v[300001];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            v[i].push_back(-1);
        }
        for(int i=0;i<n;i++) {
            int x;
            scanf("%d",&x);
            v[x].push_back(i);
        }
        for(int i=1;i<=n;i++) {
            v[i].push_back(n);
        }
        int prev=n;
        int val=-1;
        stack<int> s;
        for(int i=1;i<=n;i++) {
            int gap=0;
            for(int j=0;j+1<v[i].size();j++) {
                gap=max(gap,v[i][j+1]-v[i][j]);
            }
            for(int j=prev;j>=gap;j--) {
                s.push(i);
            }
            if (gap<=prev) {
                prev=gap-1;
            }
        }
        for(int i=prev;i>0;i--) {
            s.push(-1);
        }
        while (!s.empty()) {
            printf("%d ",s.top());
            s.pop();
        }
        printf("\n");
        for(int i=1;i<=n;i++) {
            v[i].clear();
        }
    }
}