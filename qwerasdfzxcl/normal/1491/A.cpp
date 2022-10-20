#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100], c;

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i=0;i<n;i++){
        scanf("%d", a+i);
        if (a[i]) c++;
    }
    while(q--){
        int t, k;
        scanf("%d %d", &t, &k);
        if (t==1){
            if (a[k-1]) c--;
            else c++;
            a[k-1]=1-a[k-1];
        }
        else{
            if (k<=c) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}