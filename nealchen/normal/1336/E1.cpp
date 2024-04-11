#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef unsigned long long u64;
const u32 P=998244353;
int k, cnt[65536];
u32 ans[64], res[64], c[64][64], f[64][64];
u64 base[64], a[64];
bool vis[64];
int popcnt(u64 x) {
	return cnt[x&65535]+cnt[x>>16&65535]+cnt[x>>32&65535]+cnt[x>>48&65535];
}
void search(int i, u64 x) {
	if(i==k)
		++ans[popcnt(x)];
	else {
		search(i+1, x);
		search(i+1, x^a[i]);
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1; i<65536; ++i) cnt[i]=cnt[i/2]+(i&1);
	for(int i=1; i<=n; ++i) {
		u64 x;
		scanf("%llu", &x);
		for(int j=0; j<m; ++j) {
			if(x>>j&1) {
				if(base[j]) {
					x^=base[j];
				} else {
					vis[j]=true;
					base[j]=x;
					a[k++]=x;
					break;
				}
			}
		}
	}
	if(k<=m/2) {
		u32 shl=1;
		search(0, 0);
		for(int i=k; i<n; ++i) shl=shl*2%P;
		for(int i=0; i<=m; ++i) printf("%llu%c", (u64)shl*ans[i]%P, " \n"[i==m]);
	} else {
		for(int i=m; i--; ) {
			if(vis[i]) {
				for(int j=i+1; j<m; ++j) {
					if(vis[j]&&base[i]>>j&1) base[i]^=base[j];
				}
			}
		}
		for(int i=0; i<m; ++i) {
			if(!vis[i]) base[i]=1llu<<i;
		}
		for(int i=0; i<m; ++i) {
			for(int j=i+1; j<m; ++j) {
				if(base[i]>>j&1) base[j]|=1llu<<i;
			}
		}
		k=0;
		for(int i=0; i<m; ++i) {
			if(!vis[i]) a[k++]=base[i];
		}
		search(0, 0);
		for(int i=0; i<=m; ++i) {
			c[i][0]=c[i][i]=1;
			for(int j=1; j<i; ++j)
				c[i][j]=(c[i-1][j-1]+c[i-1][j])%P;
		}
		for(int i=0; i<=m; ++i) {
			for(int j=0; j<=m; ++j) {
				for(int k=0; k<=j; ++k) {
					u32 tmp=1llu*ans[i]*c[i][k]%P*c[m-i][j-k]%P;
					if(k&1)
						res[j]=(res[j]+P-tmp)%P;
					else
						res[j]=(res[j]+tmp)%P;
				}
			}
		}
		u32 shl=1;
		if(n<m)
			for(int i=n; i<m; ++i) shl=(P+1llu)/2*shl%P;
		else
			for(int i=m; i<n; ++i) shl=shl*2%P;
		for(int i=0; i<=m; ++i) printf("%llu%c", (u64)shl*res[i]%P, " \n"[i==m]);
	}
	return 0;
}