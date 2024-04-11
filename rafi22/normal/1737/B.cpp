#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int cnt[26];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int l,r;
        cin>>l>>r;
        int ans=0;
        for(int i=l;i<=min(r,1000LL);i++)
        {
            int x=sqrt(i);
            if(i%x==0) ans++;
        }
        l=max(l,1001LL);
        int a=sqrt(l)-5;
        while(a*a<l) a++;
        int b=sqrt(r)+5;
        while(b*b>r) b--;
        int A=sqrt(l)-5;
        while(A*(A+1)<l) A++;
        int B=sqrt(r)+5;
        while(B*(B+1)>r) B--;
        int p=sqrt(l)-5;;
        while(p*(p+2)<l) p++;
        int q=sqrt(r)+5;
        while(q*(q+2)>r) q--;
        cout<<ans+max(0LL,b-a+1)+max(0LL,B-A+1)+max(0LL,q-p+1)<<endl;
    }

    return 0;
}