#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
int n,q,m,k,x,y;


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll c1,c2,c3,c4,c5;
    ll a,b,c;

    int x1,x2,y2 ,y1;

    scanf("%d" , &n);
    printf("YES\n");
    for(c1 = 0; c1 < n; c1++){
        scanf("%d %d %d %d" , &x1 , &y1, &x2, &y2);
        a = abs(min(x1,x2))%2;
        b = abs(min(y1,y2))%2;
        printf("%d\n" , 2*a+b+1);
    }
    return 0;
}