#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        int sum=0;
        for(int i=0;i<n;i++) {
            int x;
            scanf("%d",&x);
            sum+=x-1;
        }
        printf("%s\n",sum%2==0?"maomao90":"errorgorn");
    }
}