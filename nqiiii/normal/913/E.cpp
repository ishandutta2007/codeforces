#include<cstdio>
#include<string>
using namespace std;
const int maxn=10000,maxc=256;
const string inf="too young too simple,sometimes naive!";
string d[maxc+10][3];
bool cmp(const string &a,const string &b){
	if(a.size()!=b.size()) return a.size()<b.size();
	for(int i=0;i<a.size();++i) if(a[i]!=b[i]) return a[i]<b[i];
	return 0;
}
int main(){
	for(int i=0;i<maxc;++i)
		for(int j=0;j<3;++j) d[i][j]=inf;
	d[240][0]="x"; d[204][0]="y"; d[170][0]="z";
	for(;;){
		bool cg=0;
		for(int i=0;i<maxc;++i)
			for(int j=0;j<3;++j){
				if(!j&&cmp("!"+d[i][j],d[i^255][j])) d[i^255][j]="!"+d[i][j],cg=1;
				if(j&&cmp("!("+d[i][j]+")",d[i^255][0])) d[i^255][0]="!("+d[i][j]+")",cg=1;
			}
		for(int i=0;i<maxc;++i)
			for(int j=0;j<3;++j)
				if(d[i][j]!=inf)
					for(int k=0;k<maxc;++k)
						for(int l=0;l<3;++l)
							if(d[k][l]!=inf)
								for(int p=1;p<3;++p){
									string str="",od; int v=0;
									if(p==1) od="&",v=i&k;
									else if(p==2) od="|",v=i|k;
									if(p>=j) str+=d[i][j]; else str+="("+d[i][j]+")";
									str+=od;
									if(p>l) str+=d[k][l]; else str+="("+d[k][l]+")";
									if(cmp(str,d[v][p])) d[v][p]=str,cg=1;
								}
		if(!cg) break;
	}
	int t; scanf("%d",&t);
	for(;t--;){
		int v=0;
		for(int i=0;i<8;++i){
			char c=getchar(); for(;!isgraph(c);c=getchar());
			v+=(1<<i)*(c-'0');
		}
		string ans=inf;
		for(int i=0;i<3;++i) if(cmp(d[v][i],ans)) ans=d[v][i];
		printf("%s\n",ans.data());
	}
	return 0;
}