#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int x,y,z,a,b,c;scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
    if(a<x){puts("NO");return 0;}
    b+=a-x;
    if(b<y){puts("NO");return 0;}
    c+=b-y;
    if(c<z){puts("NO");return 0;}
    puts("YES");
    return 0;
}