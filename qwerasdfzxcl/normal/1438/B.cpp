#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int input[1001];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for (int i=0;i<n;i++) scanf("%d", &input[i]);
        sort(input, input+n);
        bool flag=1;
        for (int i=0;i<n-1;i++){
            if (input[i]==input[i+1]) flag=0;
        }
        if (flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}