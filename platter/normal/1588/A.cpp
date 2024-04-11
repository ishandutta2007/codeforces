#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        vector<int> a;
        vector<int> b;
        for(int i=0;i<n;i++) {
            int x;
            scanf("%d",&x);
            a.push_back(x);
        }
        for(int i=0;i<n;i++) {
            int x;
            scanf("%d",&x);
            b.push_back(x);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        bool flag=true;
        for(int i=0;i<n;i++) {
            if (a[i]!=b[i]-1&&a[i]!=b[i]) {
                flag=false;
                break;
            }
        }
        printf("%s\n",flag?"YES":"NO");
    }
    return 0;
}