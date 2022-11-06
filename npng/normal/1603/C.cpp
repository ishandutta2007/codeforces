#include <cstdio>
#include <cstring>
const int Maxn=100000;
const int Maxm=800;
const int Mod=998244353;
int f[2][Maxm+5];
int val[2][Maxm+5];
int val_len[2];
int n;
int a[Maxn+5];
void solve(){
	scanf("%d",&n);
	int ans=0;
	int nxt,cur=0;
	memset(f[0],0,sizeof f[0]);
	val_len[0]=0;
	for(int i=1;i<=n;i++){
		nxt=cur^1;
		scanf("%d",&a[i]);
		int pos=0,lst_pos=0;
		for(int j=1,k;j<a[i];j=k+1){
			k=(a[i]-1)/((a[i]-1)/j);
			int len=(a[i]-1)/j+1;
			int mn_val=a[i]/len,mx_val;
			if(mn_val*len==a[i]){
				mx_val=mn_val;
			}
			else{
				mx_val=mn_val+1;
			}
			val[nxt][++pos]=mx_val;
			while(lst_pos+1<=val_len[cur]&&val[cur][lst_pos+1]<=mn_val){
				lst_pos++;
			}
			f[nxt][pos]=(1ll*i*(len-1)+f[cur][lst_pos])%Mod;
		}
		int len=1;
		int mn_val=a[i],mx_val=a[i];
		val[nxt][++pos]=mx_val;
		while(lst_pos+1<=val_len[cur]&&val[cur][lst_pos+1]<=mn_val){
			lst_pos++;
		}
		f[nxt][pos]=(1ll*i*(len-1)+f[cur][lst_pos])%Mod;
		ans=(ans+f[nxt][pos])%Mod;
		val_len[nxt]=pos;
		cur=nxt;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}