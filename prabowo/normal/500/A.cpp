#include<bits/stdc++.h>
using namespace std;

int n, t, ke;
int edge[30002];
bool flag[30002]={};

int main(){
    scanf("%d %d", &n, &t);
    t--;
    for (int i=0; i<n-1; i++){
        scanf("%d", &ke);
        edge[i] = i + ke;
    }
    edge[n-1] = n;
    int x = 0;
    while (x < n){
        flag[x] = true;
        x = edge[x];
    }
    if (flag[t]) puts("YES"); else puts("NO");
    return 0;
}