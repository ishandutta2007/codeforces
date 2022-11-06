#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=5000;
int n,cnt[26]; char s[maxn+10];
vector<int> pos[26]; double ans;
int main(){
	scanf("%s",s); n=strlen(s);
	for(int i=0;i<n;++i) pos[s[i]-'a'].push_back(i);
	for(int i=0;i<26;++i) if(!pos[i].empty()){
		int maxv=0;
		for(int j=1;j<n;++j){
			int now=0;
			for(int k=0;k<26;++k) cnt[k]=0;
			for(int k=0;k<pos[i].size();++k) ++cnt[s[(pos[i][k]+j)%n]-'a'];
			for(int k=0;k<26;++k) if(cnt[k]==1) ++now;
			maxv=max(maxv,now);
		}
		ans+=maxv;
	}
	printf("%.9lf",ans/n);
}