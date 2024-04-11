#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
inline void qw(int&X){scanf("%d",&X);}
int n,tot,cnt;
map<string,int> m;
map<int,string> m2;
vector<string> vec[30];
string str,str2;
bool suff(string s1,string s2){
	int l1=s1.length(), l2=s2.length();
	if(l2>l1) return 0;
	for(int i=1;i<=l2;++i)
		if(s1[l1-i]!=s2[l2-i]) return 0;
	return 1;
}
int main(){
	qw(n);
	F(i,1,n){
		cin>>str;
		if(!m.count(str))
			m[str]=++tot,
			m2[tot]=str;
		scanf("%d",&cnt);
		F(j,1,cnt){
			cin>>str2;
			int l=vec[m[str]].size(), o=0;
			F2(k,0,l){
				if(suff(vec[m[str]][k],str2)) o=1;
				if(suff(str2,vec[m[str]][k])) o=2, vec[m[str]][k]=str2;
			}
			if(o==0) vec[m[str]].push_back(str2);
		}
	}
	printf("%d\n",tot);
	F(i,1,tot){
		cout<<m2[i]<<' '<<vec[i].size()<<' ';
		F2(j,0,vec[i].size()){
			cout<<vec[i][j]<<' ';
		}puts("");
	}
	return 0;
}