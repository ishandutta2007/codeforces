//----------NMFF0B0H----------//
#include <bits/stdc++.h>
#define IM using
#define GAY namespace
#define LOL std;
IM GAY LOL
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define FILE_IN "ballin.txt"
#define FILE_OUT "ballout.txt"
#define ofile                     \
    freopen(FILE_IN, "r", stdin); \
    freopen(FILE_OUT, "w", stdout)
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define nfio    \
    cin.tie(0); \
    cout.tie(0)
#define ord(a, b, c) ((a >= b) and (b >= c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1) << x)
#define pii pair<int, int>
#define piii pair<int, pii>
#define For(i, __, ___) for (int i = __; i <= ___; i++)
#define Rep(i, __, ___) for (int i = __; i >= ___; i--)
#define ordered_set tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>
#define endl "\n"
#define vi vector<int>
#define bi bigint
#define get geet
#define list_of_primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997}
typedef long long ll;
 
struct JZ
{
    long long a,b,c,d;
    friend JZ operator *(JZ x1,JZ x2)
    {
        JZ x3;
        x3.a=(x1.a*x2.a+x1.b*x2.c)%MOD;
        x3.b=(x1.a*x2.b+x1.b*x2.d)%MOD;
        x3.c=(x1.c*x2.a+x1.d*x2.c)%MOD;
        x3.d=(x1.c*x2.b+x1.d*x2.d)%MOD;
        return x3;
    }
    friend JZ operator +(JZ x1,JZ x2)
    {
        JZ x3;
        x3.a=(x1.a+x2.a)%MOD;
        x3.b=(x1.b+x2.b)%MOD;
        x3.c=(x1.c+x2.c)%MOD;
        x3.d=(x1.d+x2.d)%MOD;
        return x3;
    }
}A,E;
JZ Pows(int x)
{
    JZ X=E,Y=A;
    while(x)
    {
        if(x%2)
            X=Y*X;
        Y=Y*Y;
        x/=2;
    }
    return X;
}
struct Node
{
    int l,r,mid;
    JZ sum,lazy;
}tre[400005];
int n;
int num[100005];
JZ build(int l,int r,int x)
{
    tre[x].l=l;
    tre[x].r=r;
    tre[x].mid=(l+r)/2;
    tre[x].lazy=E;
    if(l!=r)
        return tre[x].sum=build(l,tre[x].mid,x*2)+build(tre[x].mid+1,r,x*2+1);
    else
        return tre[x].sum=Pows(num[l]-1);
}
void add(int l,int r,JZ nums,int x)
{
    if(tre[x].l==l && r==tre[x].r)
    {
        tre[x].sum=nums*tre[x].sum;
        tre[x].lazy=nums*tre[x].lazy;
    }
    else
    {
        add(tre[x].l,tre[x].mid,tre[x].lazy,x*2);
        add(tre[x].mid+1,tre[x].r,tre[x].lazy,x*2+1);
        tre[x].lazy=E;
        if(l<=tre[x].mid && r>tre[x].mid)
        {
            add(l,tre[x].mid,nums,x*2);
            add(tre[x].mid+1,r,nums,x*2+1);
        }
        else
        {
            if(r<=tre[x].mid)
                add(l,r,nums,x*2);
            else
                add(l,r,nums,x*2+1);
        }
        tre[x].sum=tre[x*2].sum+tre[x*2+1].sum;
    }
}
JZ ask(int l,int r,int x)
{
    if(l==tre[x].l && r==tre[x].r)
        return tre[x].sum;
    else
    {
        add(tre[x].l,tre[x].mid,tre[x].lazy,x*2);
        add(tre[x].mid+1,tre[x].r,tre[x].lazy,x*2+1);
        tre[x].lazy=E;
        if(l<=tre[x].mid && r>tre[x].mid)
            return ask(l,tre[x].mid,x*2)+ask(tre[x].mid+1,r,x*2+1);
        else
        {
            if(r<=tre[x].mid)
                return ask(l,r,x*2);
            else
                return ask(l,r,x*2+1);
        }
    }
}
int main()
{
    fio;
    E.b=E.c=A.d=0;
    E.a=E.d=A.a=A.b=A.c=1;
    int q,a,b,c,s;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    cin>>num[i];
    build(1,n,1);
    while(q--)
    {
        cin>>s;
        if(s==1)
        {
            cin>>a>>b>>c;
            add(a,b,Pows(c),1);
        }
        else
        {
            cin>>a>>b;
            cout<<(ask(a,b,1)).a<<endl;
        }
    }
}