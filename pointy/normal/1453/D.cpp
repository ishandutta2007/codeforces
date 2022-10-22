#include<bits/stdc++.h>
using namespace std;
int a[2001],cnt;
long long u[61];
void fill(int x)
{
    a[++cnt]=1;
    for (int i=1;i<=x-2;i++) a[++cnt]=0;
}
void f(long long x)
{
    long long tot=x;
    for (int i=60;i>=2;i--)
    {
        while (tot>=u[i]) 
        {
            fill(i);
            tot-=u[i];
        }
    }
    //assert(tot==0);
}
inline int read()
{
    char C=getchar();
    int F=1,ANS=0;
    while (C<'0'||C>'9')
    {
        if (C=='-') F=-1;
        C=getchar();
    }
    while (C>='0'&&C<='9')
    {
        ANS=ANS*10+C-'0';
        C=getchar();
    }
    return F*ANS;
} 
int main()
{
    u[0]=1;
    for (int i=1;i<=60;i++) u[i]=u[i-1]*2ll;
    for (int i=2;i<=60;i++) u[i]-=2ll;
    int T=read();
    while (T--)
    {
        long long n;
        cin >> n;
        cnt=0;
        if (n%2==1) 
        {
            cout << -1 << endl;
            continue;
        }
        f(n);
        cout << cnt << endl;
        for (int i=1;i<=cnt;i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}