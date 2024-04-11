#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }
        int ret=0;
        set<int> s;
        int val=0;
        s.insert(0);
        for(int i=0;i<n;i++) {
            if (s.find(arr[i]^val)!=s.end()) {
                s.clear();
                s.insert(val);
            }
            else {
                ret++;
                val^=arr[i];
                s.insert(val);
            }
        }
        printf("%d\n",ret);
    }
}