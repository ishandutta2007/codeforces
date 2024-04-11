#include<bits/stdc++.h>
using namespace std;
inline int scan(){
    int x;
    scanf("%d",&x);
    return x;
}
int main(){
    double a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    a*=2;
    double dist = sqrt((d-b)*(d-b)+(e-c)*(e-c));
    int ans = ceil(dist/a);
    printf("%d",ans);
}