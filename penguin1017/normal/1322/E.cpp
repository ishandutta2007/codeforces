#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=5e5+9;
const ll mod=998244353;
int st[N],Lmin[N][19],Rmin[N][19],Lmax[N][19],Rmax[N][19],a[N],b[N],cnt[N],temp[3];
int getmax(int p,int len){
	return max(Lmax[p-len/2][st[len]],Rmax[p+len/2][st[len]]);
}
int getmin(int p,int len){
	return min(Lmin[p-len/2][st[len]],Rmin[p+len/2][st[len]]);
}
int Median(int a,int b,int c){
	return a^b^c^max({a,b,c})^min({a,b,c});
}
int main(){
//	freopen("text.in","r",stdin);
	int n;
	scanf("%d",&n);
	rep(i,1,n+1){
		scanf("%d",&a[i]);
		Lmin[i][0]=Rmin[i][0]=Lmax[i][0]=Rmax[i][0]=a[i];
		Lmin[i][1]=Rmin[i][1]=Lmax[i][1]=Rmax[i][1]=a[i];
	}
	rep(i,2,19){
		int len=1<<i;
		if(len>n)break;
		rep(p,1,n+1){
			if(p+len>n+1)break;
			Lmin[p][i]=min(Lmin[p][i-1],Lmin[p+len/2][i-1]);
			Lmax[p][i]=max(Lmax[p][i-1],Lmax[p+len/2][i-1]);
		}
		per(p,1,n+1){
			if(p-len<0)break;
			Rmin[p][i]=min(Rmin[p][i-1],Rmin[p-len/2][i-1]);
			Rmax[p][i]=max(Rmax[p][i-1],Rmax[p-len/2][i-1]);
		}
	}
	st[0]=-1;
	rep(i,1,N)st[i]=st[i>>1]+1;
	int ans=0;
	b[1]=a[1],b[n]=a[n];
	rep(i,2,n){
		if(Median(a[i-1],a[i],a[i+1])==a[i]){
			b[i]=a[i];
			continue;
		}
		cnt[i]=max(cnt[i-1]-1,0);
		rep(k,cnt[i]+1,cnt[i-1]+2){
			if(k+i>n)break;
		//	cout<<i<<' '<<k<<"check\n";
			int len=2*k+1;
			if(a[i]>a[i-1]){
				if(k&1){
					temp[0]=getmax(i,len);
					temp[1]=getmin(i,len-2);
				}
				else{
					temp[1]=getmin(i,len);
					temp[0]=getmax(i,len-2);
				}
				if(temp[0]>=temp[1])break;
				++cnt[i];
				//cout<<temp[0]<<' '<<temp[1]<<' '<<temp[2]<<"temp\n";
			}
			else{
				if(k&1){
					temp[0]=getmax(i,len-2);
					temp[1]=getmin(i,len);
				}
				else{
					temp[1]=getmin(i,len-2);
					temp[0]=getmax(i,len);
				}
				if(temp[0]>=temp[1])break;
				++cnt[i];
			}
		}
		ans=max(ans,cnt[i]);
	//	cout<<i<<' '<<cnt[i]<<"cnt\n";
		if(a[i]>a[i-1]){
			if(cnt[i]&1)b[i]=getmax(i,2*cnt[i]+1);
			else b[i]=getmin(i,2*cnt[i]+1);
		}
		else{
			if(cnt[i]&1)b[i]=getmin(i,2*cnt[i]+1);
			else b[i]=getmax(i,2*cnt[i]+1);
		}
	}
	printf("%d\n",ans);
	//rep(i,1,n+1)cout<<cnt[i]<<' ';
	rep(i,1,n+1)printf("%d ",b[i]);
}
/*
8
41 18467 6334 26500 19169 15724 11478 29358 
*/