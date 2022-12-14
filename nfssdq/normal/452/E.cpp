/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         2.0*acos(0.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

const int MX = int(3e5)+10;

int cmp(int *r,int a,int b,int l){
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
}
int wa[MX],wb[MX],wws[MX],wv[MX];
int rnk[MX],height[MX];

void DA(int *r,int *sa,int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) wws[i]=0;
    for(i=0;i<n;i++) wws[x[i]=r[i]]++;
    for(i=1;i<m;i++) wws[i]+=wws[i-1];
    for(i=n-1;i>=0;i--) sa[--wws[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wws[i]=0;
        for(i=0;i<n;i++) wws[wv[i]]++;
        for(i=1;i<m;i++) wws[i]+=wws[i-1];
        for(i=n-1;i>=0;i--) sa[--wws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        //printf("p = %d\n", p );
    }
}
void calheight(int *r,int *sa,int n){
  //  memset(height,0,sizeof(height));
  //  memset(rnk,0,sizeof(rnk));
    int i,j,k=0;
    for(i=1;i<=n;i++) rnk[sa[i]]=i;
    for(i=0;i<n; height[rnk[i++]] = k )
    for(k?k--:0,j=sa[rnk[i]-1]; r[i+k]==r[j+k]; k++);
}
int sa[MX],data[MX],n,p,q;
char str[MX];

char ss[3][350001];
int LCP[350001], seg[1230001], N;
void insert(int idx, int s, int e, int p, int v){
    if(s == e){
        seg[idx] = v;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    seg[idx] = min(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}
int query(int idx, int s, int e, int st, int ed){
    if(s == st && e == ed) return seg[idx];
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        int a = query(idx * 2 + 1, s, mid, st, mid);
        int b = query(idx * 2 + 2, mid + 1, e, mid + 1, ed);
        return min(a,b);
    }
}
int query1(int idx, int s, int e, int st, int ed, int v){
    if(seg[idx] > v) return N;
    if(s == e) return s;
    int mid = (s + e) / 2;
    if(ed <= mid) return query1(idx * 2 + 1, s, mid, st, ed, v);
    else if(st > mid) return query1(idx * 2 + 2, mid + 1, e, st, ed, v);
    else {
        int a = query1(idx * 2 + 1, s, mid, st, mid, v);
        if(a < N) return a;
        return query1(idx * 2 + 2, mid + 1, e, mid + 1, ed, v);
    }
}
LL ar[350001], cn[3][350001];
void go(int l, int r, int m){
    if((r - l + 1) < 3) return;
    int v = query(0, 1, N-1, l + 1, r);
    int p = query1(0, 1, N-1, l+1, r, v);
    LL a = (cn[0][r] - cn[0][l-1])*(cn[1][r] - cn[1][l-1])
            *(cn[2][r] - cn[2][l-1]);
    ar[m + 1] += a;
    ar[v + 1] -= a;
    go(l, p - 1, v);
    while(p < r){
        int b = query1(0, 1, N-1, p+1, r, v);
        if(b > r){
            go(p, r, v);
            return;
        } else {
            go(p, b-1, v);
            p = b;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z;
    cin >> ss[0] >> ss[1] >> ss[2];
    N = 0;
    REP(i, 3){
        a = strlen(ss[i]);
        REP(j, a) data[N++] = ss[i][j];
        if(i == 0) data[N++] = '#';
        if(i == 1) data[N++] = '?';
    }
    DA(data,sa,N+1,128);
    calheight(data,sa,N);
    a = 0; b = strlen(ss[0]) + 1; c = b + strlen(ss[1]) + 1;
    FOR(i, 2, N + 1) {
        if(sa[i] >= a && sa[i] < b) cn[0][i-1]++;
        if(sa[i] >= b && sa[i] < c) cn[1][i-1]++;
        if(sa[i] >= c) cn[2][i-1]++;
        insert(0, 1, N-1, i - 1, height[i]);
    }
    FOR(i, 1, N) REP(j, 3) cn[j][i] += cn[j][i - 1];
    go(1, N-1, 0);
    for(int i = 1; i < N; i++) ar[i] = (((ar[i] + ar[i - 1]) % mod)+mod)% mod;
    a = 310000;
    REP(i, 3) a = min(a, (LL)strlen(ss[i]));
    for(int i = 1; i <= a; i++) cout << ar[i] << " ";
    cout << endl;
}