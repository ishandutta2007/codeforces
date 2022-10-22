#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int q;
    scanf("%d",&q);
    for(int t=0;t<q;t++) {
        int u,v;
        scanf("%d %d",&u,&v);
        vector<int> v0;
        vector<int> v1;
        for(int i=0;i<30;i++) {
            if (u&(1<<i)) {
                v0.push_back(i);
            }
            if (v&(1<<i)) {
                v1.push_back(i);
            }
        }
        if (v0.size()<v1.size()||u>v) {
            printf("NO\n");
            continue;
        }
        bool flag=true;
        for(int i=0;i<v1.size();i++) {
            if (v0[i]>v1[i]) {
                flag=false;
                break;
            }
        }
        printf("%s\n",flag?"YES":"NO");
    }
}