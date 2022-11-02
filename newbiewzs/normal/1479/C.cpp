#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int l,r;
vector<int>u,v,w;
void link(int x,int y,int z){
	if(x>y && y!=-1)swap(x,y);
	u.push_back(x);
	v.push_back(y);
	w.push_back(z);
}
void clear(){
	u.pop_back();
	v.pop_back();
	w.pop_back();
}
const int N=50;
int L[N],R[N];
bool flag=0;
int jl;
int top=21;
int x[N],y[N],head;
void out(){
	puts("YES");
	cout<<jl<<" "<<v.size()<<endl;
	for(int k=0;k<v.size();k++){
		if(v[k]!=-1)printf("%d %d %d\n",u[k],v[k],w[k]);
		else printf("%d %d %d\n",u[k],jl,w[k]);
	}
}
int main(){
	scanf("%d%d",&l,&r);
	L[1]=R[1]=1;
	int pre=1;
	for(int i=2;i<=21;i++){
		L[i]=1e9;
		for(int k=1;k<i;k++){
			link(k,i,pre);
			L[i]=min(L[i],L[k]+pre);
			R[i]=max(R[i],R[k]+pre);
		}
		pre*=2;
	}
	for(int i=1;i<=21;i++){
		if(L[i]>=l and R[i]<=r){
			link(i,-1,1);
		//	cout<<"se"<<i<<endl;
		}
		else if(l>=L[i] and r<=R[i]){
			x[++head]=l;
			y[head]=r;
			break;
		}
		else if(l<L[i] and r>=L[i]){
			x[++head]=L[i];
			y[head]=min(r,R[i]);
		}
		else if(l<=R[i] and r>R[i]){
			x[++head]=max(l,L[i]);
			y[head]=R[i];
		}
	}
	for(int i=1;i<=head;i++){
		top++;
		for(int k=21;k>=1;k--){
			int gg=x[i]-L[k];
			if(R[k]+gg>y[i])continue;
			if(gg<=0)continue;
			x[i]=R[k]+gg+1;
			link(k,top,gg);
			if(x[i]==y[i]+1){
				break;
			}
		}
		link(top,-1,1);
	}
	jl=head+22;
	out();
//	else cout<<u[210]<<" "<<v[210]<<" "<<w[210];
	return 0;
}