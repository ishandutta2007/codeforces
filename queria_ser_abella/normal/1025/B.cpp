#include <bits/stdc++.h>
#define maxn 200200
#define pb push_back
using namespace std;

int a[maxn];
int b[maxn];

int pr(int x){
    for(int i=2;i*i<=x;i++)
        if(x%i == 0)
            return 0;
    return 1;
}

int main() {
    vector<int> v;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",a+i,b+i);
    for(int i=1;i*i<=max(a[0],b[0]);i++){
        if(a[0]%i == 0){
            v.pb(a[0]/i);
            v.pb(i);
        }
        if(b[0]%i == 0){
            v.pb(b[0]/i);
            v.pb(i);
        }
    }
    for(int i=0;i<v.size();i++){
        int num = v[i];
        if(!pr(num) || num == 1) continue;
        int ok = 0;
        for(int j=0;j<n;j++)
            if(a[j]%num == 0 || b[j]%num == 0) ok++;
        if(ok == n){
            printf("%d\n",num);
            return 0;
        }
    }
    printf("-1\n");
}