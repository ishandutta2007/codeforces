#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=400+5;
int n,ans;
vector<char>s[N];
inline void ins(int i,char ch){
	if (s[i].empty()){
		s[i].push_back(ch);
		return;
	}
	if (ch=='u'){
		s[i].push_back('o'),s[i].push_back('o');
		return;
	}
	if (s[i].back()=='k' && ch=='h')
		s[i].pop_back(),ins(i,'h');
	else s[i].push_back(ch);
}
bool chk(int x,int y,int s1,int s2,int opt){
	//if (x==8 && y==5) printf("%d %d\n",s1,s2);
	if (s[x][s1]!=s[y][s2] && !opt) return 0;
	if (s1==s[x].size()-1 && s2==s[y].size()-1) return 1;
	int res=0;
	if (s1+1<s[x].size() && s2+1<s[y].size())
		res|=chk(x,y,s1+1,s2+1,0);
	if (s1+1<s[x].size() && s[x][s1+1]=='h' && s2+2<s[y].size() && s[y][s2+2]=='h' && s[y][s2+1]=='k'){
		//if (x==3 && y==5) printf("%d %d\n",s1,s2);
		res|=chk(x,y,s1+1,s2+2,1);
	}
	if (s1+1<s[x].size() && s[x][s1+1]=='u' && s2+2<s[y].size() && s[y][s2+2]=='o' && s[y][s2+1]=='o'){
		//if (x==8 && y==5) printf("%d %d\n",s1,s2);
		res|=chk(x,y,s1+1,s2+2,1);
	}
	return res;
}
int main(){
	//freopen("f.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		s[i]=vector<char>();
		char ch=0;
		while (ch>'z' || ch<'a') ch=getchar();
		s[i].push_back('#');
		while (ch>='a' && ch<='z'){
			//printf("%c\n",ch);
			ins(i,ch);
			ch=getchar();
		}
		for (int j=1;j<i;++j)	
			if (chk(i,j,0,0,0) || chk(j,i,0,0,0)){
				--ans;
			//	printf("%d\n",i);
				break;
			}
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}