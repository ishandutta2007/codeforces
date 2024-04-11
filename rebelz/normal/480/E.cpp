#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k;
char a[2005][2005];
int lf[2005][2005],rg[2005][2005],q1[2005],q2[2005],qx[2005],qy[2005],d[2005][2005],ans[2005];

int main(){
	n=readint(); m=readint(); k=readint();
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for(int i=1;i<=k;i++) qx[i]=readint(),qy[i]=readint(),a[qx[i]][qy[i]]='X';
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]!='X') lf[i][j]=lf[i][j-1]+1;
	for(int i=1;i<=n;i++) for(int j=m;j>=1;j--) if(a[i][j]!='X') rg[i][j]=rg[i][j+1]+1;
	int now=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='X') continue;
			if(d[i-1][j]==d[i][j-1]) d[i][j]=a[i-d[i-1][j]][j-d[i-1][j]]=='X'?d[i-1][j]:d[i-1][j]+1;
			else d[i][j]=min(d[i-1][j],d[i][j-1])+1;
			now=max(now,d[i][j]);
		}
	}
	ans[k]=now;
	for(int i=k;i>=2;i--){
		a[qx[i]][qy[i]]='.';
		for(int j=qy[i];j<=m;j++){
			if(a[qx[i]][j]=='X') break;
			lf[qx[i]][j]=lf[qx[i]][j-1]+1;
		}
		for(int j=qy[i];j>=1;j--){
			if(a[qx[i]][j]=='X') break;
			rg[qx[i]][j]=rg[qx[i]][j+1]+1;
		}
		int tst=ans[i];
		while(1){
			if(tst==n) break;
			int fr1=0,re1=0,fr2=0,re2=0,ub=max(1,qx[i]-tst),db=ub+tst;
			bool fl=true;
			for(int j=ub;j<=db;j++){
				while(fr1<re1&&lf[j][qy[i]]<=lf[q1[re1-1]][qy[i]]) re1--;
				q1[re1++]=j;
				while(fr2<re2&&rg[j][qy[i]]<=rg[q2[re2-1]][qy[i]]) re2--;
				q2[re2++]=j;
			}
			if(!fl) break;
//			cout<<"test "<<i<<' '<<lf[q1[fr1]][qy[i]]<<' '<<rg[q2[fr2]][qy[i]]<<' '<<tst<<endl;
			if(lf[q1[fr1]][qy[i]]+rg[q2[fr2]][qy[i]]-1>=tst+1){
				tst++;
				continue;
			}
			for(int j=db+1;j<=n;j++){
				if(a[j][qy[i]]=='X') break;
				while(fr1<re1&&q1[fr1]<j-tst) fr1++;
				while(fr2<re2&&q2[fr2]<j-tst) fr2++;
				while(fr1<re1&&lf[j][qy[i]]<=lf[q1[re1-1]][qy[i]]) re1--;
				q1[re1++]=j;
				while(fr2<re2&&rg[j][qy[i]]<=rg[q2[re2-1]][qy[i]]) re2--;
				q2[re2++]=j;
//				cout<<"test "<<i<<' '<<lf[q1[fr1]][qy[i]]<<' '<<rg[q2[fr2]][qy[i]]<<' '<<tst<<endl;
				if(lf[q1[fr1]][qy[i]]+rg[q2[fr2]][qy[i]]-1>=tst+1){
					tst++,fl=false;
					break;
				}
			}
			if(fl) break;
		}
		ans[i-1]=tst;
	}
	for(int i=1;i<=k;i++) printf("%d\n",ans[i]);
	return 0;
}