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
#define PI         acos(-1.0)
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

const int N = int(1e6)+10;

int cmp(int *r,int a,int b,int l){
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
}
int wa[N],wb[N],wws[N],wv[N];
int rnk[N],height[N];

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
    }
}
void calheight(int *r,int *sa,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++) rnk[sa[i]]=i;
    for(i=0;i<n;height[rnk[i++]]=k)
        for(k?k--:0,j=sa[rnk[i]-1];r[i+k]==r[j+k];k++);
}

int sa[N],data[N],n,p,q;

deque < int > dq[500001];

int nxt[500001], tmp[500001], id[500001];
stack < int > s;
string S;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin >> S;
//    if(n == 1){
//        cout << 0 << endl;
//        return 0;
//    }

    REP(i, n) {
        if(S[i] == '(') data[i] = 10;
        else data[i] = 11;
        nxt[i] = -1;
    }
    data[n] = 0;
    DA(data,sa,n+1,128);
    calheight(data,sa,n);


    REP(i, n){
        if(S[i] == '(') s.push(i);
        else {
            if(s.size() == 0) continue;
            nxt[s.top()] = i;
            s.pop();
        }
    }

    height[1] = 0;
    FOR(i, 1, n+1) {
        tmp[sa[i]] = sa[i] + height[i];
    }

    LL res = 0;
    int cnt = 0;

    nxt[n] = -1;
    for(int i = n-1; i >= 0; i--){
        if(nxt[i] == -1) continue;
        if(nxt[nxt[i]+1] == -1){
            id[i] = ++cnt;
        } else {
            id[i] = id[nxt[i]+1];
        }
        dq[id[i]].push_front(nxt[i]);
        if(dq[id[i]].back() < tmp[i]) continue;
        int lb = lower_bound(dq[id[i]].begin(), dq[id[i]].end(), tmp[i]) - dq[id[i]].begin();
        res += dq[id[i]].size() - lb;

//        cout << i << " " << res << " " << tmp[i] << endl;

    }

    cout << res << endl;

}