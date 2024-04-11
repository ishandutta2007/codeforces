#include <bits/stdc++.h>
using namespace std;

char str[100001];

void print(int n) {
    for(int i=0;i<n;i++) {
        printf("%c",str[i]);
    }
    for(int i=n-1;i>=0;i--) {
        printf("%c",str[i]);
    }
    printf("\n");
}

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        scanf("%s",str);
        for(int i=1;i<=n;i++) {
            if (i==n) {
                print(n);
                break;
            }
            if (str[i-1]==str[i]) {
                if (i==1) {
                    print(1);
                    break;
                }
            }
            else if (str[i-1]<str[i]) {
                print(i);
                break;
            }
        }
    }
    return 0;
}