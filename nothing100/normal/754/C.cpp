#include<bits/stdc++.h>
using namespace std;
int t,n,m;
string s[110],ss[110];
int f[110],pre[110][110],no[110][110],ans[110];
int can(char x){
	if (x>='a'&&x<='z') return 0;
	if (x>='A'&&x<='Z') return 0;
	if (x>='0'&&x<='9') return 0;
	return 1;
}
int check(int z,int x,int y){
	if (y+s[x].length()>ss[z].length()) return 0;
	for (int i=0;i<s[x].length();i++)
	if (ss[z][y+i]!=s[x][i]) return 0;
	if ((y+s[x].length()!=ss[z].length())&&(!can(ss[z][y+s[x].length()]))) return 0;
	if ((y-1>=0)&&(!can(ss[z][y-1]))) return 0;
	return 1;
}
int main(){
	scanf("%d",&t);
	while (t--){
		memset(no,0,sizeof(no));
		scanf("%d",&n);
		for (int i=0;i<n;i++) cin>>s[i];
		scanf("%d\n",&m);
		for (int i=0;i<m;i++){
			f[i]=-1;
			getline(cin,ss[i]);
            if (ss[i][0]!='?'){
            	for (int j=0;j<n;j++)
            	if (check(i,j,0)) f[i]=j;
            }
            else{
				for (int j=0;j<n;j++)
				for (int k=0;k<ss[i].length();k++)
				if (check(i,j,k)) no[i][j]=1;
            }
		}
		for (int i=0;i<m;i++)
		for (int j=0;j<n;j++) pre[i][j]=-1;
		for (int i=0;i<m;i++){
			if (f[i]!=-1){
				if (i){
					for (int j=0;j<n;j++)
					if (j!=f[i]&&pre[i-1][j]!=-1) pre[i][f[i]]=j;
				}
				else pre[i][f[i]]=0;
			}
			else{
				for (int j=0;j<n;j++)
				if (!no[i][j]){
					if (i){
						for (int k=0;k<n;k++)
						if (k!=j&&pre[i-1][k]!=-1) pre[i][j]=k;
					}
					else pre[i][j]=0;
				}
			}
		}
		int bo=-1;
		for (int i=0;i<n;i++)
		if (pre[m-1][i]!=-1) bo=i;
		if (bo==-1) printf("Impossible\n");
		else{
			for (int i=m-1;i>=0;i--){
				ans[i]=bo;
				bo=pre[i][bo];
			}
			for (int i=0;i<m;i++){
				if (ss[i][0]=='?'){
					cout<<s[ans[i]];
					for (int j=1;j<ss[i].length();j++) printf("%c",ss[i][j]);
					printf("\n");
				}
				else cout<<ss[i]<<endl;
			}
		}
	}
	return 0;
}