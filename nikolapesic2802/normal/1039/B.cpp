#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
char c[4];
bool pitaj(long long x,long long y)
{
    printf("%lld %lld\n",x,y);
    fflush(stdout);
    //cout.flush();
    scanf("%s",c);
    if(c[0]=='B')
    {
        exit(0);
    }
    if(c[0]=='Y')
    {
        if(x==y)
        {
            exit(0);
        }
        return true;
    }
    return false;
}
int main()
{
    //srand(time(NULL));
    long long n;
    long long k;
    scanf("%lld %lld",&n,&k);
    long long a=1,b=n;
    while(true)
    {
        long long razlika=b-a+1;
        if(razlika>4*k+3)
        {
            long long mid=(a+b)/2;
            if(pitaj(a,mid))
            {
                b=mid;
            }
            else
            {
                a=mid+1;
            }
        }
        else
        {
            long long rnd=a+rng()%razlika;
            pitaj(rnd,rnd);
        }
        a=max((long long)1,a-k);
        b=min(n,b+k);
    }
    return 0;
}