#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a1[200001];
int b1[200001];
map<pair<int,int>,int>used;
int cnt=0;
int gcd(int a,int b){
    if (b==0) return a;
    return __gcd(a,b);
}
pair<int,int> f(int i){
     int a,b;
     a=a1[i];
     b=b1[i];
     b=-b;
     if (a<0) {
         a=-a;
         b=-b;
     }
     if (b<0){
        b=abs(b);
        a=abs(a);
        return {-(b/gcd(b,a)),a/gcd(b,a)};
     } else {
        return {(b/gcd(b,a)),a/gcd(b,a)};
     }
}
int main()
{
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a1[i];
    for (int i=1;i<=n;i++) cin>>b1[i];
    for (int i=1;i<=n;i++){
        if (a1[i]==0 && b1[i]!=0) continue;
        if (a1[i]==0){
            cnt++;
            continue;
        }
         used[f(i)]++;
    }
    int res=0;
    for (int i=1;i<=n;i++){
        if (a1[i]==0) continue;
        res=max(res,used[f(i)]);
    }
    cout<<res+cnt;
    return 0;
}
/*

4
1 2 1 0
-6 -12 -6 0

*/