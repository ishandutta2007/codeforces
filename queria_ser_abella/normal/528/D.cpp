#include <bits/stdc++.h>
#define pii pair<int,int>
#define maxn 600600
#define ll long long
#define debug
using namespace std;

int p[maxn];

typedef complex<double> cpx; const double pi = acos(-1.0);
// DFT if type = 1, IDFT if type = -1
// If you are multiplying, remember to let EACH vector with n >= sum of degrees of both polys
// n is required to be a power of 2
void FFT(cpx v[], cpx ans[], int n, int type, int p[]) { // p[n]
	assert(!(n & (n - 1))); int i, sz, o; p[0] = 0;
	for(i = 1; i < n; i++) p[i] = (p[i >> 1] >> 1) | ((i & 1)? (n >> 1) : 0); // repetition can be avoided
	for(i = 0; i < n; i++) ans[i] = v[p[i]];
	for(sz = 1; sz < n; sz <<= 1) {
		const cpx wn(cos(type * pi / sz), sin(type * pi / sz));
		for(o = 0; o < n; o += (sz << 1)) {
			cpx w = 1;
			for(i = 0; i < sz; i++) {
				const cpx u = ans[o + i], t = w * ans[o + sz + i];
				ans[o + i] = u + t;
				ans[o + i + sz] = u - t;
				w *= wn;
			}
		}
	}
	if(type == -1) for(i = 0; i < n; i++) ans[i] /= n;
}

int ok[maxn];

char s[maxn];
char t[maxn];

cpx v[maxn];
cpx pat[maxn];
cpx ans[maxn];

int main(){
    char dna[4] = {'A','T','C','G'};
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    scanf(" %s %s",s,t);
    for(int u=0;u<4;u++){
        for(int i=0;i<3*n;i++)
            v[i] = pat[i] = 0;
        int qtd = 0, last = -1e9;
        for(int i=0;i<n;i++){
            if(s[i] == dna[u])
                last = i;
            if(last+k >= i)
                v[i] = 1;
        }
        last = 1e9;
        for(int i=n-1;i>=0;i--){
            if(s[i] == dna[u])
                last = i;
            if(last-k <= i)
                v[i] = 1;
        }
        for(int i=0;i<m;i++)
            if(t[i] == dna[u]){
                qtd++;
                pat[m-i-1] = 1;
            }
        int N = n+m;
        while(N & (N-1)) N++;
        debug("\n\n%c\n",dna[u]);
        for(int i=0;i<N;i++)
            debug("%d ",(int)(v[i].real()+0.5));
        debug("\n");
        for(int i=0;i<N;i++)
            debug("%d ",(int)(pat[i].real()+0.5));
        debug("\n");
        FFT(v,ans,N,1,p);
        for(int i=0;i<N;i++)
            debug("(%.2f;%.2f) ",ans[i].real(),ans[i].imag());
        debug("\n");
        FFT(pat,v,N,1,p);
        for(int i=0;i<N;i++)
            v[i] *= ans[i];
        FFT(v,ans,N,-1,p);
        for(int i=0;i<N;i++)
            debug("%d ",(int)(ans[i].real()+0.5));
        debug("\n");
        for(int i=0;i<n;i++)
            ok[i] += ((int)(ans[i+m-1].real()+0.5) == qtd);
    }
    int ans = 0;
    for(int i=0;i<n;i++)
        if(ok[i] == 4) ans++;
    printf("%d\n",ans);
}