#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree_set;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

const double PI=acos(-1.0);

struct Complex
{
    double r,i;
    Complex(double _r = 0.0,double _i = 0.0)
    {
        r = _r; i = _i;
    }
    Complex operator +(const Complex &b)
    {
        return Complex(r+b.r,i+b.i);
    }
    Complex operator -(const Complex &b)
    {
        return Complex(r-b.r,i-b.i);
    }
    Complex operator *(const Complex &b)
    {
        return Complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};
void change(Complex y[],int len)
{
    int i,j,k;
    for(i = 1, j = len/2;i < len-1; i++)
    {
        if(i < j)swap(y[i],y[j]);
        k = len/2;
        while( j >= k)
        {
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    }
}

void FFT(Complex y[],int len,int on)
{
    change(y,len);
    for(int h = 2; h <= len; h <<= 1)
    {
        Complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j+=h)
        {
            Complex w(1,0);
            for(int k = j;k < j+h/2;k++)
            {
                Complex u = y[k];
                Complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}


Complex p1[1<<20], p2[1<<20], p3[1<<20];
int ab[1<<20], a2b2[1<<20];

string s,t;
int n,m,k;

ll a[4][200010];

char ss[5]="ATCG";

map<char,int> mp;

int ans[200010];

ll gao(double x) {
	return x>=0?(ll)(fabs(x)+0.5):-(ll)(fabs(x)+0.5);
}


void solve(int d) {
	int N=1;
	while(N<=n+m) N*=2;
	REP(i,N) p1[i]=i<n?Complex(a[d][i]>0?1:0):Complex(0);
	REP(i,N) p2[i]=i<m?Complex(t[i]==ss[d]?-1:0):Complex(0);
	FFT(p1,N,1);
	FFT(p2,N,1);
	REP(i,N) p1[i]=p1[i]*p2[i];
	FFT(p1,N,-1);
	REP(i,N) ab[i]=gao(p1[i].r);
	
	REP(i,N) p1[i]=i<n?Complex(a[d][i]>0?1:0):Complex(0);
	REP(i,N) p2[i]=i<m?Complex(t[i]==ss[d]?1:0):Complex(0);
	FFT(p1,N,1);
	FFT(p2,N,1);
	REP(i,N) p1[i]=p1[i]*p2[i];
	FFT(p1,N,-1);
	REP(i,N) a2b2[i]=gao(p1[i].r);
	
	REP(i,n-m+1) {
		int C=(a2b2[i+m-1]-ab[i+m-1])/2;
		ans[i]+=C;
	}
}

int main()
{
	mp['A']=0;
	mp['T']=1;
	mp['C']=2;
	mp['G']=3;
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	cin>>s>>t;
	reverse(t.begin(),t.end());
	REP(i,n) {
		int d=mp[s[i]];
		a[d][max(i-k,0)]++;
		a[d][min(i+k+1,n)]--;
	}
	REP(i,4)
	REP(j,n) a[i][j+1]+=a[i][j];
	REP(i,4) solve(i);
	int cnt=0;
	REP(i,n-m+1) {
		if(ans[i]==m) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}