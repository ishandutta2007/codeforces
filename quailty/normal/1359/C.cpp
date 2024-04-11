#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int h,c,t;
        scanf("%d%d%d",&h,&c,&t);
        if(2*t<=h+c)
        {
            printf("2\n");
            continue;
        }
        int k=(h-t)/(2*t-h-c);
        ll k1=k,k2=k+1;
        ll d1=(k1*c+(k1+1)*h)-(2*k1+1)*t;
        ll d2=(2*k2+1)*t-(k2*c+(k2+1)*h);
        printf("%d\n",2*(k+(d1*(2*k2+1)>d2*(2*k1+1)))+1);
    }   
    return 0;
}