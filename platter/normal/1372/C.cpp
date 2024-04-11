#include <bits/stdc++.h>
using namespace std;

int arr[200000];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        vector<int> v;
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
            arr[i]--;
            if (arr[i]!=i) {
                v.push_back(i);
            }
        }
        if (v.empty()) {
            printf("0\n");
            continue;
        }
        bool flag=true;
        for(int i=1;i<v.size();i++) {
            if (v[i-1]+1!=v[i]) {
                flag=false;
                break;
            }
        }
        printf("%d\n",flag?1:2);
    }
}