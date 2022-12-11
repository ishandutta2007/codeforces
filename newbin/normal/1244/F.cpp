#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
struct node{
    int l, r;
    node(int a = 0, int b = 0){l = a; r = b;}
};
const int maxn = 4e5 + 50;
vector<node> g;
int n, k;
char s[maxn];
int a[maxn], b[maxn];
int main()
{
	cin>>n>>k;

	scanf("%s", s);
	for(int i = 0; i < n; ++i){
        if(s[i] == 'W') a[i] = 0; else a[i] = 1;
        b[i] = a[i];
        b[i+n] = b[i];
        a[i+n] = a[i];
	}
	int l ,r; l = 0;
	while(l < n*2){
        r = l;
        while(r+1 < n*2 && a[r+1] == a[r]) r++;
        if(r != l) {
            g.push_back(node(l, r));
           // cout<<"l:"<<l<<" r:"<<r<<endl;
        }
        l = r+1;

	}
	if(g.size() == 0){
        if(k&1) for(int i = 0; i < n; ++i) a[i] ^= 1;
	}
	if(g.size() == 1){
        int L = g[0].l;
       int  R = g[0].r;
        int d = n-(R-L+1);
        if(2*k <= d){
            for(int i = L-1; i >= L-k; --i){
                int p = (i+n)%n;
                int p2 = (i+1+n)%n;
                a[p] = a[p2];
            }
            for(int i = R-1; i <= R+k; ++i){
                int p = (i+n)%n;
                int p2 = (i-1+n)%n;
                a[p] = a[p2];
            }
            if(k&1){
                for(int i = R+k+1; (i+n)%n != L; ++i){
                    a[i%n] ^= 1;
                }
            }
        }
        else{
            if(d&1){
                for(int i = R+1; i%n != L; ++i){
                    int p = i%n;
                    int p2 = (i+n-1)%n;
                    a[p] = a[p2];
                }
            }
            else{
                for(int i = R+1; i <= R+d/2; ++i){
                    int p = i%n;
                    int p2 = (i+n-1)%n;
                    a[p] = a[p2];
                }
                for(int i = L-1;i >= L - d/2; --i){
                    int p = (i+n)%n;
                    int p2 = (i+n+1)%n;
                    a[p] = a[p2];
                }
            }
        }
	}
	else{
	for(int u = 0; u +1 < g.size(); ++u){
        int L = g[u].r;
        int R = g[u+1].l;
        if(L == g[0].l+n) break;
        //cout<<"L:"<<L<<" R:"<<R<<endl;
        int d = R-L-1;
        if(2*k <= d){
            for(int i = L+1;i <= L+k; ++i){
                b[i] = b[i-1];
            }
            for(int i = R-1;i >= R-k; --i){
                b[i] = b[i+1];
            }
            if(k&1){
                for(int i = L+k+1; i < R-k; ++i) b[i] ^= 1;
            }
        }
        else{
            if(d&1){
                for(int i = L+1;i < R; ++i) b[i] = b[i-1];
            }
            else{
                for(int i = L+1;i <= L+d/2; ++i){
                    b[i] = b[i-1];
                }
                for(int i = R-1;i >= R-d/2; --i){
                    b[i] = b[i+1];
                }
            }
        }
        for(int i = L+1; i < R; ++i){
            //cout<<b[i]<<endl;
            a[i%n] = b[i];
        }
	}
	}
	for(int i = 0; i < n; ++i){
        if(!a[i]) printf("W");
        else printf("B");
	}
}