#include <bits/stdc++.h>
using namespace std;

int arr[50];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }
        set<int> s;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                s.insert(arr[j]-arr[i]);
            }
        }
        printf("%d\n",s.size());
    }
}