#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long k;
int main(){
    scanf("%d%lld",&n,&k);
    while ((k&1)==0){
        k/=2;
        ans++;
    }
    printf("%d\n",++ans);
}