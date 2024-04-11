#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,tot,cnt;
int ans1[500005],ans2[500005],ans3[500005],ans4[500005],cnt1[500005],cnt2[500005],cnt3[500005],cnt4[500005],l[305][305],num0[305],num1[305];
vector<int> a[305][305],b[305][305],v;
string s[305][305],t[305][305];

void to1(int sx,int sy,int ex,int ey){
	if(sx!=ex) ans1[++tot]=sx,ans2[tot]=sy,ans3[tot]=ex,ans4[tot]=sy;
	if(sy!=ey) ans1[++tot]=ex,ans2[tot]=sy,ans3[tot]=ex,ans4[tot]=ey;
}

void to2(int sx,int sy,int ex,int ey){
	if(sx!=ex) cnt1[++cnt]=sx,cnt2[cnt]=sy,cnt3[cnt]=ex,cnt4[cnt]=sy;
	if(sy!=ey) cnt1[++cnt]=ex,cnt2[cnt]=sy,cnt3[cnt]=ex,cnt4[cnt]=ey;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>s[i][j];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>t[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			l[i][j]=s[i][j].length();
			for(int k=l[i][j]-1;k>=0;k--) a[i][j].push_back(s[i][j][k]-'0');
			if(i==1&&j==1) for(int k=0;k<a[i][j].size();k++) v.push_back(a[i][j][k]);
		}
	}
	for(int i=2;i<=m;i++) for(int j=0;j<a[1][i].size();j++) ans1[++tot]=1,ans2[tot]=i,ans3[tot]=1,ans4[tot]=1,v.push_back(a[1][i][j]);
	for(int i=2;i<=n;i++) for(int j=0;j<a[i][1].size();j++) ans1[++tot]=i,ans2[tot]=1,ans3[tot]=1,ans4[tot]=1,v.push_back(a[i][1][j]);
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			for(int k=0;k<a[i][j].size();k++){
				if(a[i][j][k]==0) ans1[++tot]=i,ans2[tot]=j,ans3[tot]=1,ans4[tot]=j,num0[j]++;
				else ans1[++tot]=i,ans2[tot]=j,ans3[tot]=i,ans4[tot]=1,num1[i]++;
			}
		}
	}
	for(int i=3;i<=m;i++) for(int j=1;j<=num0[i];j++) ans1[++tot]=1,ans2[tot]=i,ans3[tot]=1,ans4[tot]=2;
	for(int i=3;i<=n;i++) for(int j=1;j<=num1[i];j++) ans1[++tot]=i,ans2[tot]=1,ans3[tot]=2,ans4[tot]=1;
	for(int i=0;i<v.size();i++)
		if(v[i]==0) ans1[++tot]=1,ans2[tot]=1,ans3[tot]=1,ans4[tot]=2;
		else ans1[++tot]=1,ans2[tot]=1,ans3[tot]=2,ans4[tot]=1;
	v.clear();
	memset(num0,0,sizeof(num0)); memset(num1,0,sizeof(num1));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			l[i][j]=t[i][j].length();
			for(int k=0;k<l[i][j];k++) b[i][j].push_back(t[i][j][k]-'0');
			if(i==1&&j==1) for(int k=0;k<b[i][j].size();k++) v.push_back(b[i][j][k]);
		}
	}
	for(int i=2;i<=m;i++) for(int j=0;j<b[1][i].size();j++) cnt1[++cnt]=1,cnt2[cnt]=i,cnt3[cnt]=1,cnt4[cnt]=1,v.push_back(b[1][i][j]);
	for(int i=2;i<=n;i++) for(int j=0;j<b[i][1].size();j++) cnt1[++cnt]=i,cnt2[cnt]=1,cnt3[cnt]=1,cnt4[cnt]=1,v.push_back(b[i][1][j]);
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			for(int k=0;k<b[i][j].size();k++){
				if(b[i][j][k]==0) cnt1[++cnt]=i,cnt2[cnt]=j,cnt3[cnt]=1,cnt4[cnt]=j,num0[j]++;
				else cnt1[++cnt]=i,cnt2[cnt]=j,cnt3[cnt]=i,cnt4[cnt]=1,num1[i]++;
			}
		}
	}
	for(int i=3;i<=m;i++) for(int j=1;j<=num0[i];j++) cnt1[++cnt]=1,cnt2[cnt]=i,cnt3[cnt]=1,cnt4[cnt]=2;
	for(int i=3;i<=n;i++) for(int j=1;j<=num1[i];j++) cnt1[++cnt]=i,cnt2[cnt]=1,cnt3[cnt]=2,cnt4[cnt]=1;
	for(int i=0;i<v.size();i++)
		if(v[i]==0) cnt1[++cnt]=1,cnt2[cnt]=1,cnt3[cnt]=1,cnt4[cnt]=2;
		else cnt1[++cnt]=1,cnt2[cnt]=1,cnt3[cnt]=2,cnt4[cnt]=1;
	
	printf("%d\n",tot+cnt);
	for(int i=1;i<=tot;i++) printf("%d %d %d %d\n",ans1[i],ans2[i],ans3[i],ans4[i]);
	for(int i=cnt;i>=1;i--) printf("%d %d %d %d\n",cnt3[i],cnt4[i],cnt1[i],cnt2[i]);
	return 0;
}