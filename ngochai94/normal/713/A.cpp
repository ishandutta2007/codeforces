#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 10007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

long long t,n;
char c;

long long cnt[1<<20];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    scanf("%lld\n", &t);
    while(t--)
    {
        scanf("%c %lld\n", &c, &n);
        //cout<<n;
        long long cur=0;
        long long b=1;
        while(n)
        {
            cur+=(n%10)%2==1? b: 0;
            n/=10;
            b*=2;
        }
        //cout<<' '<<cur<<endl;
        if(c=='+')
        {
            cnt[cur]++;
        }
        else if(c=='-')
        {
            cnt[cur]--;
        }
        else cout<<cnt[cur]<<endl;
    }
}