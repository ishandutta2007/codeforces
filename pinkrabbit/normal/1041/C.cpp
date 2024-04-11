#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
int n,m,d;
int p[300001];
int a[300001];
typedef pair<int,int> pii;
set<pii> st;
int Ans[300001],t;
int A[300001];
bool cmp(int i,int j){return a[i]<a[j];}
int main(){
	scanf("%d%d%d",&n,&m,&d);
	F(i,1,n) scanf("%d",a+i), p[i]=i;
	sort(p+1,p+n+1,cmp);
	sort(a+1,a+n+1);
	st.insert(pii(m+2,0));
	F(i,1,n){
		pii P=pii(a[i]-d,0);  // < a[i] - d
		set<pii> :: iterator it= st.lower_bound(P);
		if(it!=st.begin()){
			--it;
			int nw=it->second;
			st.erase(it);
			st.insert(pii(a[i],nw));
			Ans[i]=nw;
		}
		else{
			++t;
			st.insert(pii(a[i],t));
			Ans[i]=t;
		}
	}
	F(i,1,n) A[p[i]]=Ans[i];
	printf("%d\n",t);
	F(i,1,n) printf("%d ",A[i]);
	return 0;
}