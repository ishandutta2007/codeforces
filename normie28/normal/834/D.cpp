#include <bits/stdc++.h>
#define LL long long
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
using namespace std;
#define  si set<int>
struct node
{
int l;
int r;
si t;
int ln;
int rn;
};
vector<node> st; node h;
const int N=35001;
int n,k;
LL dp[N][51],ans;
int a[N],c[N];
int le=1,ri;
int buildTree(int l, int r)
{
st.push_back(h);
int res,a,b;
res=st.size()-1;
st[res].l=l;
st[res].r=r;
if (l==r)
{
st[res].t.insert(0);
}
else
{
int mid=(l+r)/2;
a=buildTree(l,mid);
b=buildTree(mid+1,r);
st[res].ln=a;
st[res].rn=b;
st[res].t.insert(st[st[res].ln].t.begin(),st[st[res].ln].t.end());
st[res].t.insert(st[st[res].rn].t.begin(),st[st[res].rn].t.end());
}
return res;
}
void add(int l,int r){
	while(le<l)ans-=!--c[a[le++]];
	while(le>l)ans+=!c[a[--le]]++;
	while(ri>r)ans-=!--c[a[ri--]];
	while(ri<r)ans+=!c[a[++ri]]++;
}
void cal(int k,int from,int to,int l,int r){
	if(l>r)return;
	int m=l+r>>1,best;
	LL &tmp=dp[m][k]=0;
	FOR(i,from,min(to,m)){
		add(i,m);
		if(ans+dp[i-1][k-1]>tmp){
			tmp=ans+dp[i-1][k-1];
			best=i;
		}
	}
	cal(k,from,best,l,m-1);
	cal(k,best,to,m+1,r);
}
int main(){Accel
	cin>>n>>k;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)add(1,i),dp[i][1]=ans;
	FOR(i,2,k)cal(i,1,n,1,n);
	cout<<dp[n][k]<<endl;
}