#include<cstdio>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#include<set>
using namespace std;
inline int Max(int X,int Y){return X<Y?Y:X;}
inline int Min(int X,int Y){return X<Y?X:Y;}
int n,m;
set<int> vv;
set<pair<int,int> > st;
bool vis[200001];
int que[200001],l,r;
int Ans[200001],ans;
int main(){
	scanf("%d%d",&n,&m);
	int x,y; F(i,1,m) scanf("%d%d",&x,&y), st.insert(make_pair(Min(x,y),Max(x,y)));
	F(i,1,n) vv.insert(i);
	F(i,1,n){
		if(!vis[i]){
			vis[i]=1; vv.erase(i);
			que[l=r=1]=i;
			while(l<=r){
				int u=que[l++];
				for(set<int>::iterator j=vv.begin();j!=vv.end();){
					if(!st.count(make_pair(Min(u,*j),Max(u,*j))))
						que[++r]=*j, vis[*j]=1, vv.erase(j++);
					else ++j;
				}
			}
			++Ans[r]; ++ans;
		}
	}
	printf("%d\n",ans);
	F(i,1,n) while(Ans[i]--) printf("%d ",i);
	return 0;
}